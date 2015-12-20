local Example = {}

function Example.add(t1, t2)
    local ret = {}
    for k, v in pairs(t1) do
        ret[v] = true
    end
    for k, v in pairs(t2) do
        ret[v] = true
    end
    mt = {__tostring=to_string}
    setmetatable(ret, mt)

    return ret
end

function to_string(t) 
    ret = ''
    for k, v in pairs(t) do
        ret = ret..k..'\n' 
    end
    return ret
end


return Example
