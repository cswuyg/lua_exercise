/**
 * @file lua_math.h 
 * @author cswuyg
 * @date 2015/12/08 22:43:20
 * @brief 类封装给Lua使用
 *  
 **/


#ifndef __LUA_MY_DATE_H__
#define __LUA_MY_DATE_H__ 
extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

namespace lua_my_date {

// 对象
int new_date(lua_State* L);
// 对象里的操作
int lua_cur_time(lua_State* L);
int lua_set_year(lua_State* L);
int lua_get_year(lua_State* L);
int lua_get_date(lua_State* L);
int lua_set_date(lua_State* L);

// 模块注册
int luaopen_mydate(lua_State* L);

}

#endif  //__LUA_MY_DATE_H__

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
