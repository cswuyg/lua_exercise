/***************************************************************************
 * 
 * Copyright (c) 2017 cswuyg. All Rights Reserved
 * 
 **************************************************************************/
/**
 * @file test.cpp
 * @author cswuyg
 * @date 2017/07/24 12:44:38
 * @brief C++程序嵌入Lua解释器
 * 给lua的输入参数是table，lua的输出是string
 *  
 **/
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

void test_dostring(lua_State* L, const std::string& file_path) {
    std::ifstream ifs;    
    ifs.open(file_path.c_str());
    if (!ifs.is_open()) {
        return ;
    }
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    std::string file_info(buffer.str());
    luaL_dostring(L, file_info.c_str());
    lua_getglobal(L, "comment");
    lua_createtable(L, 2, 0);
    lua_pushstring(L, "TB");
    lua_pushstring(L, "王小波");
    lua_rawset(L, -3);
    lua_pushstring(L, "TC");
    lua_pushstring(L, "散文");
    lua_rawset(L, -3);
    lua_call(L, 1, 1);
    std::string lua_ret = lua_tostring(L, -1);

    //file_info = "TB='王小波' TC='散文'" + file_info;
    std::cout << "lua ret:" << lua_ret << std::endl;
}

int main(int argc, char* argv[]) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    test_dostring(L, "test.lua");
    lua_close(L);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
