/***************************************************************************
 * 
 * Copyright (c) 2015 cswuyg All Rights Reserved
 * 
 **************************************************************************/
/**
 * @file lua_my_math.cpp 
 * @author cswuyg
 * @date 2015/12/08 22:43:27
 * @brief 包装要导出的函数
 *  
 **/
#include "lua_my_math.h"
#include "my_math.h"

namespace lua_math {
int wrapper_add(lua_State* L) {
    int a = luaL_checkinteger(L, 1);
    int b = luaL_checkinteger(L, 2);

    int c = math::add(a, b);
    lua_pushinteger(L, c);
    return 1;
}

// 模块函数
static const luaL_Reg math_lib[] = {
    {"add", wrapper_add},
    {NULL, NULL}
};

// math模块注册 
int luaopen_math(lua_State* L) {
    std::cout << "luaopen_math" << std::endl;
    luaL_checkversion(L);
    luaL_newlib(L, math_lib);
    return 1;
}

}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
