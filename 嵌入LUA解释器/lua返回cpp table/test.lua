--package.cpath = package.cpath..';/usr/local/app/theodorewu/src/test_lua/lua_install/share/?.so;'
--package.path = package.path..';/usr/local/app/theodorewu/src/test_lua/lua_install/share/?.lua;'
--print(package.cpath)
--print('-----------------')
--print(package.path)
package.cpath = package.cpath..';'..TAF_LUA_INSTALL_PATH..'/?.so;'
package.path = package.path..';'..TAF_LUA_INSTALL_PATH..'/?.lua;'
local Json = require('cjson')
local md5 = require('md5')
--
function comment(json) 
    ret_table = {}
    local json_obj = Json.decode(json)
    local ret = {}
    ret['ui_id'] = 2
    ret['title'] = json_obj.title
    
    if type(json_obj.imgList) == 'table' 
    then ret['img'] = json_obj.imgList[1]
    else
        ret['img'] = json_obj.imgList
    end

    ret['url'] = json_obj.url
    ret['item_id'] = md5.sumhexa(ret['url']..ret['title'])

    ret['subInfo_array'] = {}
    ret['subInfo_array'][1] = {}
    ret['subInfo_array'][1]['subInfo_id'] = 1
    ret['subInfo_array'][1]['icon_name'] = '小说'
    ret['subInfo_array'][1]['dis'] = '这是小说的描述信息'
    ret_table[1] = Json.encode(ret)
    ret_table[2] = Json.encode(ret)
    return ret_table
end
