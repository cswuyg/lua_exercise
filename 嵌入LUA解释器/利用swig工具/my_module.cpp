/**
 * @file my_module.cpp
 * @author cswuyg
 * @date 2015/12/20 18:08:58
 * @brief 我的测试模块
 *  
 **/

#include "my_module.h"

int add(int a, int b) {
    return a + b;
}

std::string Hello::get_info() {
    return "this is ret from my module";
}

Hello* Hello::get_test() {
    return _test_p;
}

bool Hello::set_test(Hello* p) {
    _test_p = p;
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
