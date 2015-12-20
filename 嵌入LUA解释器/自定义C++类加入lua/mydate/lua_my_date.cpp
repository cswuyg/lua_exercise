/**
 * @file lua_my_date.cpp 
 * @author cswuyg
 * @date 2015/12/08 22:43:27
 * @brief 类封装给Lua使用
 *  
 **/
#include "lua_my_date.h"
#include "my_date.h"

namespace lua_my_date {

// 对象
int new_date(lua_State* L) {
    my_date::Date **d =  (my_date::Date**)lua_newuserdata(L, sizeof(my_date::Date*));
    *d = new my_date::Date;
    luaL_getmetatable(L, "my_date");
    lua_setmetatable(L, -2);
    return 1;
}

// 对象里的操作

int lua_cur_time(lua_State* L) {
    my_date::Date **d = (my_date::Date**)luaL_checkudata(L, 1, "my_date");
    luaL_argcheck(L, d != NULL, 1, "invalid user data");
    lua_pushstring(L, (*d)->cur_time().c_str());
    return 1;
}

int lua_set_year(lua_State* L) {
    my_date::Date **d = (my_date::Date**)luaL_checkudata(L, 1, "my_date");
    luaL_argcheck(L, d != NULL, 1, "invalid user data");
    luaL_checktype(L, -1, LUA_TSTRING);
    std::string year = lua_tostring(L, -1);
    (*d)->set_year(year);
    return 1;
}

int lua_get_year(lua_State* L) {
    my_date::Date **d = (my_date::Date**)luaL_checkudata(L, 1, "my_date");
    luaL_argcheck(L, d != NULL, 1, "invalid user data");
    lua_pushstring(L, (*d)->get_year().c_str());
    return 1;
}

int lua_set_date(lua_State* L) {
    my_date::Date **d = (my_date::Date**)luaL_checkudata(L, 1, "my_date");
    luaL_argcheck(L, d != NULL, 1, "invalid user data");
    luaL_checktype(L, -1, LUA_TUSERDATA);
    my_date::Date **date = (my_date::Date**)luaL_checkudata(L, 2, "my_date");
    (*d)->set_date(*date);
    return 1;
}

int lua_get_date(lua_State* L) {
    my_date::Date **d = (my_date::Date**)luaL_checkudata(L, 1, "my_date");
    luaL_argcheck(L, d != NULL, 1, "invalid user data");
    my_date::Date **date =  (my_date::Date**)lua_newuserdata(L, sizeof(my_date::Date*));
    *date = (*d)->get_date(); 
    luaL_getmetatable(L, "my_date");
    lua_setmetatable(L, -2);
    return 1;
}

// 类函数
static const luaL_Reg date_c[] = {
    {"date", new_date},
    {NULL, NULL}
};

// 类里的成员函数封装
static const luaL_Reg date_f[] = {
    {"cur_time", lua_cur_time},
    {"set_year", lua_set_year},
    {"get_year", lua_get_year},
    {"set_date", lua_set_date},
    {"get_date", lua_get_date},
    {NULL, NULL}
};

// math模块注册 
int luaopen_mydate(lua_State* L) {
    luaL_checkversion (L);

    // 创建一个metatable，关联到my_data字符串。
    // 这个metatable以后的userdata会用上
    luaL_newmetatable(L, "my_date");
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    luaL_setfuncs(L, date_f, 0);
    lua_settop(L, 0); // metatable用完，把它从栈顶拿走
    // 把date函数导出在栈顶
    luaL_newlib(L, date_c);
    return 1;
}

}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
