/***************************************************************************
 * 
 * Copyright (c) 2015 cswuyg All Rights Reserved
 * 
 **************************************************************************/
/**
 * @file lua_wrapper.cpp
 * @author cswuyg
 * @date 2015/12/08 22:43:27
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "lua_wrapper.h"
#include "mydate/lua_my_date.h"

namespace lua_wrapper {

static const luaL_Reg lualibs[] = {
    {"mydate", lua_my_date::luaopen_mydate},
    {NULL, NULL}
};

// 全局注册
bool lua_init(lua_State* L) {
    const luaL_Reg *lib = lualibs;
    for (; lib->func != NULL; ++lib) {
        lib->func(L);
        lua_setglobal(L, lib->name);
    }
}

}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
