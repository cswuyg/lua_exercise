/***************************************************************************
 * 
 * Copyright (c) 2015 cswuyg All Rights Reserved
 * 
 **************************************************************************/
/**
 * @file lua_my_math.h 
 * @author cswuyg
 * @date 2015/12/08 22:43:20
 * @brief 包装要导出的函数
 *  
 **/

#ifndef _LUA_MY_MATH_H_ 
#define _LUA_MY_MATH_H_ 
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

namespace lua_math {

int op_add(lua_State* L);

// 模块注册
int luaopen_math(lua_State* L);

}

#endif  //_LUA_MY_MATH_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
