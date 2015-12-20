/**
 * @file lua_wrapper.h
 * @author cswuyg
 * @date 2015/12/08 22:43:20
 * @brief 
 *  
 **/

#ifndef  _LUA_WRAPPERE_H_
#define  _LUA_WRAPPERE_H_

extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

namespace lua_wrapper {
// 全局注册
bool lua_init(lua_State* L);

}

#endif  //_LUA_WRAPPERE_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
