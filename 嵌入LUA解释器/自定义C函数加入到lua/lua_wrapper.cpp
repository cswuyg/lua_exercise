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
#include "mymath/lua_my_math.h"

namespace lua_wrapper {

static const luaL_Reg lualibs[] = {
    {"mymath", lua_math::luaopen_math},
    {NULL, NULL}
};

// 全局注册
bool lua_init(lua_State* L) {
    const luaL_Reg *lib = lualibs;
    for (; lib->func != NULL; ++lib) {
        std::cout << "lua_init" << std::endl;
        //把lib->func执行的结果作为lib->name的value保存到package.loaded 中      
        luaL_requiref(L, lib->name, lib->func, 1); 
        //清空状态机L
        lua_settop(L, 0);
/*
跟上面两行代码等价：
lib->func(L);//执行注册，L栈顶是注册了函数的table             
lua_setglobal(L, lib->name);  //把栈顶的table作为value，以lib->name 作为key保存到全局表中。
全局表和package.loaded对于table说效果等价。
*/
    }
}

}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
