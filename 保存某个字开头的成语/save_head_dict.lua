--[[
生成某个字开头的所有成语
cswuyg 2015.12.1
思路：
1、先在外面把成语词典转换为UTF8格式；
2、使用正则表达式剔除非四字成语；
3、使用正则找出四字成语的首字
----]]
require('math')
md5 = require('md5')
mongo = require "mongo"

client = mongo.client{ host = 'xxxx.com', port='27031' }
insert_to_mongo = function(t)
    client.test.head:insert(t)--这里是单条写入，批量写入会快点，但mongo驱动在批量写入时有core，暂不使用批量
    local r = client:runCommand ("getLastError",1,"w",1)
end

-- 获取table长度
function table_length(t)
    local count = 0
    for _ in pairs(t) do count = count + 1 end
    return count
end

-- 拷贝table,单层
function table_deep_copy(a)
    local b = {}
    for k, v in pairs(a) do
        b[k] = v
    end
    return b
end

-- 获取table的交集
function table_intersection(table_a, table_b)
    list_inter = {}
    for k, v in ipairs(table_a) do
        list_inter[v] = 1 
    end
    for k, v in ipairs(table_b) do
        if list_inter[v] == 1 then
            list_inter[v] = 2
        end
    end
    ret = {}
    for k, v in pairs(list_inter) do
        if v == 2 then
            table.insert(ret, v)
        end
    end
    return ret
end

-- table数据打乱
function mix_up_table(items)
    for key, value in ipairs(items) do
        rand = math.random(#items)
        items[rand], items[key] = items[key], items[rand]
    end
    return items
end

-- table 合并
function table_union(t1, t2)
    local ret = {}
    for k, v in ipairs(t1) do
        ret[k] = v
    end
    for k, v in ipairs(t2) do
        ret[k] =v 
    end
    return ret
end

-- 删除table项
function del_item_by_value(list, value)
    for k, v in ipairs(list) do
        if v == value then
            table.remove(list, k)
            return true
        end
    end
    return false
end
--
-- 删除table项
function del_item_by_key(list, key)
    for k, v in ipairs(list) do
        if k == key then
            table.remove(list, k)
            return true
        end
    end
    return false
end

-- 判断当前item是否在list中
function check_item_exists(list, item) 
    for _, v in ipairs(list) do
        if v == item then
            return true
        end
    end
    return false
end

-- 成语操作控制
idioms_ctrl = {
    idioms_path = nil , -- 成语词典路径
    idioms = {}, -- 内存成语词典
    idioms_len = 0, -- 成语词典长度
    head_table = {}
}

--建立head 词典
function idioms_ctrl:build_head_dict()
    self.head_table = {}
    for k, v in ipairs(self.idioms) do
        head = string.match(v, '([%z\1-\127\194-\244][\128-\191]*).*')
        if self.head_table[head] then 
            table.insert(self.head_table[head], v)
        else
            self.head_table[head] = {v}
        end
    end
end

-- 加载字典到idioms中，并创建head_dict
function idioms_ctrl:load_dict()
    local file = assert(io.open(self.idioms_path, 'r'))
    for line in file:lines() do
        local idiom = {}
        local_, count = string.gsub(line, "[^\128-\193]", "")
        if count == 4 then
            for uchar in string.gmatch(line, "[%z\1-\127\194-\244][\128-\191]*") do 
                table.insert(idiom, uchar)
            end
            item = table.concat(idiom)
            if string.len(item) > 0 then
                table.insert(self.idioms, table.concat(idiom))
                self.idioms_len = self.idioms_len + 1
            end
        end
    end
    idioms_ctrl:build_head_dict()
end

-- 写到mongodb和文件
function idioms_ctrl:write_all_head()
    print('all result length:'..table_length(self.head_table))
    self.f_w = assert(io.open(self.result_path, 'w'))
    for head, idioms in pairs(self.head_table) do
        idioms_ctrl:write_result(head, idioms)
    end
end

-- 写入结果到结果文件
function idioms_ctrl:write_result(head, list)
    self.f_w:write(head..':'..table.concat(list, ',')..'  len:'..#list..'\n')
    info = table.concat(list, ',')
    xx = {['_id']=head, ['data']=info, ['len']=#list}
    insert_to_mongo(xx)
    return false
end

-- 全部跑
function run(idioms_dict_path, result_path)
    print('dict :'..idioms_dict_path)
    idioms_ctrl.result_path = result_path
    idioms_ctrl.idioms_path = idioms_dict_path
    for k, v in pairs(idioms_ctrl) do 
        print(k, v)
    end
    idioms_ctrl:load_dict()
    idioms_ctrl:write_all_head()
end

-- 主函数
function main() 
    math.randomseed( tonumber(tostring(os.time()):reverse():sub(1,6)) )

    local s = os.clock()
    print(arg[0])
    print(arg[1])
    print(arg[2])
    if not arg[1] or not arg[2] then
        print('input format: lua xx.lua [idioms_dict_path] [result_path]')
        return false
    end
    print('arg[1]:'..arg[1])
    print('arg[2]:'..arg[2])
    run(arg[1], arg[2])
    local e = os.clock()
    print('cost second:'..e-s)
end

main()

