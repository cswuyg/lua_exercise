/**
 * @file main.cpp
 * @author cswuyg
 * @date 2015/12/08 12:44:38
 * @brief 
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

#include "lua_wrapper.h"

void test_dofile(lua_State* L, const std::string& file_path) {
    luaL_dofile(L, "test.lua");
    std::string lua_ret = lua_tostring(L, 1);
    std::cout << "lua ret:" << lua_ret << std::endl;
}

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
    std::string lua_ret = lua_tostring(L, 1);
    std::cout << "lua ret:" << lua_ret << std::endl;
}

int main(int argc, char* argv[]) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    lua_wrapper::lua_init(L);

    test_dostring(L, "test.lua");
    test_dofile(L, "test.lua");
    lua_close(L);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
