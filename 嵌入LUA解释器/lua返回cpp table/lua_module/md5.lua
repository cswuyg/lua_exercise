----------------------------------------------------------------------------
-- $Id: md5.lua,v 1.4 2006/08/21 19:24:21 carregal Exp $
----------------------------------------------------------------------------

local string = string or require"string"
--TAF_LUA_INSTALL_PATH变量在Cpp程序中定义
local core_func = package.loadlib(TAF_LUA_INSTALL_PATH.."core.so", "luaopen_md5_core")
local core = core_func()

----------------------------------------------------------------------------
-- @param k String with original message.
-- @return String with the md5 hash value converted to hexadecimal digits

function core.sumhexa (k)
  k = core.sum(k)
  return (string.gsub(k, ".", function (c)
           return string.format("%02x", string.byte(c))
         end))
end

return core
