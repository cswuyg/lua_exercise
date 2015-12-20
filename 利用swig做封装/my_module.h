/**
 * @file my_module.h
 * @author cswuyg
 * @date 2015/12/20 18:05:05
 * @brief 我的测试模块
 *  
 **/
#ifndef  __MY_MODULE_H_
#define  __MY_MODULE_H_

#include <string>

int add(int a, int b);

class Hello {
public:
    std::string get_info();
    bool set_test(Hello* p);
    Hello* get_test();
private:
    Hello* _test_p;
};


#endif  //__MY_MODULE_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
