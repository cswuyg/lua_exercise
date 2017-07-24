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
 * 给lua的输入参数是json化的string，lua的输出是table
 * lua需要使用到cjson模块、md5模块
 * cpp代码要指定lua脚本能加载的模块路径
 * 需要提前编译好cjson.so和core.so&md5.lua  
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
#include <sys/time.h>
class CostTime {
    public:
        CostTime() {
            start();
        }
        ~CostTime() {};
        void start(){
            ::gettimeofday(&_start_tv, NULL);
        }
        long end() {
            ::gettimeofday(&_end_tv, NULL);
            return cost_us();
        }
        long cost_us() {
            return (_end_tv.tv_sec - _start_tv.tv_sec) * 1000000 + (_end_tv.tv_usec - _start_tv.tv_usec);
        }
    private:
        struct timeval _start_tv;
        struct timeval _end_tv;
};

void test_dostring(lua_State* L, const std::string& file_path) {
    std::ifstream ifs;    
    ifs.open(file_path.c_str());
    if (!ifs.is_open()) {
        return ;
    }
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    //std::string lib_path = "/usr/local/app/cswuyg/src/test_lua/lua_install/share/";
    std::string lib_path = "./lua_module/";
    std::string file_info = "TAF_LUA_INSTALL_PATH='" + lib_path + "' \n";
    file_info += buffer.str();
    int i_ret = luaL_dostring(L, file_info.c_str());
    if (i_ret != 0) {
        std::cout << "error msg:" << lua_tostring(L, -1) << std::endl;
    }
    lua_getglobal(L, "comment");
    std::string json_str = "{\"docId\":\"4002344222\",\"newsTime\":\"1496982120\",\"url\":\"http://kuaibao.qq.com/s/20170609A03Y2E00\",\"title\":\"据说，这就是你们玩王者荣耀时候的心情，太形象了\",\"from\":\"小爱大人\",\"imgList\":[\"http://cdn.read.html5.qq.com/image?src=read&q=5&imgflag=5&r=4&w=176&h=176&imageUrl=http%3A%2F%2Finews%2Egtimg%2Ecom%2Fnewsapp%5Fmatch%2F0%2F1553015606%2F0&referUrl=http%3A%2F%2Fkuaibao%2Eqq%2Ecom%2Fs%2F20170609A03Y2E00\",\"http://cdn.read.html5.qq.com/image?src=read&q=5&imgflag=5&r=4&w=176&h=176&imageUrl=http%3A%2F%2Finews%2Egtimg%2Ecom%2Fnewsapp%5Fmatch%2F0%2F1553015907%2F0&referUrl=http%3A%2F%2Fkuaibao%2Eqq%2Ecom%2Fs%2F20170609A03Y2E00\",\"http://cdn.read.html5.qq.com/image?src=read&q=5&imgflag=5&r=4&w=176&h=176&imageUrl=http%3A%2F%2Finews%2Egtimg%2Ecom%2Fnewsapp%5Fmatch%2F0%2F1646867337%2F0&referUrl=http%3A%2F%2Fkuaibao%2Eqq%2Ecom%2Fs%2F20170609A03Y2E00\"]}";
    lua_pushstring(L, json_str.c_str());
    lua_call(L, 1, 1);

    if (lua_gettop(L) == 1 && lua_istable(L, -1)) {
        int len = lua_objlen(L, -1);
        std::cout << len << std::endl;
        for (int i = 1; i <= len; ++i) {
            lua_pushnumber(L, i);
            lua_gettable(L, -2);
            std::string info = lua_tostring(L, -1);
            std::cout << info << std::endl; 
            lua_pop(L, 1);
        }
    } else { 
    std::string lua_ret = lua_tostring(L, -1);
    std::cout << "ret:" << lua_ret << std::endl;
    }
}

int main(int argc, char* argv[]) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    CostTime cost_time;

    test_dostring(L, "test.lua");
    std::cout << "cost us=" << cost_time.end() << std::endl;
    lua_close(L);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
