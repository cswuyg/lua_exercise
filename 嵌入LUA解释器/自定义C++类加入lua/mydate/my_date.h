/**
 * @file my_date.h 
 * @author cswuyg
 * @date 2015/12/08 22:33:20
 * @brief  功能类
 *  
 **/

#ifndef  __MY_DATE_H__ 
#define  __MY_DATE_H__ 
#include <string>

namespace my_date {

class Date {
public:
    Date() {}
    ~Date() {}
    std::string cur_time();
    bool set_year(const std::string& year);
    std::string get_year();
    bool set_date(Date* date);
    Date* get_date();
private:
    std::string _year;
    Date* _date;
};
}

#endif  //__MY_DATE_H__

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
