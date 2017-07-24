/**
 * @file main.cpp
 * @author cswuyg
 * @date 2015/12/20 18:13:51
 * @brief 
 *  
 **/
 extern "C"
 {
     #include <lua.h>
     #include <lualib.h>
     #include <lauxlib.h>
 };
extern "C" {
    extern int luaopen_my_module(lua_State* L);
}
#include <iostream>

int main() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaopen_my_module(L);
    if (luaL_dofile(L, "./test.lua") != 0) {
        std::cout << "do test.lua error" << std::endl;
    }
    lua_close(L);

    return 0;
}



/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
