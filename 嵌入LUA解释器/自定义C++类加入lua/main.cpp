/**
 * @file main.cpp
 * @author cswuyg
 * @date 2015/12/08 12:44:38
 * @brief 测试自定义类导出给Lua使用，借助userdata
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

void test_dostring(lua_State* L, const std::string& file_path) {
    std::ifstream ifs;    
    ifs.open(file_path.c_str());
    if (!ifs.is_open()) {
        return ;
    }
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    std::string file_info(buffer.str());
    int ret = luaL_dostring(L, file_info.c_str());
    if (ret == 0) {
        std::string lua_ret = lua_tostring(L, 1);
        std::cout << "lua ret:" << lua_ret << std::endl;
    } else {
        std::cout << "lua exc error:" << ret << std::endl;
    }
}

int main(int argc, char* argv[]) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    lua_wrapper::lua_init(L);

    test_dostring(L, "test.lua");
    lua_close(L);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
