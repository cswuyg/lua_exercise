/**
 * @file my_date.cpp
 * @author cswuyg
 * @date 2015/12/08 22:33:23
 * @brief  功能类
 *  
 **/
#include "my_date.h"
#include <iostream>
#include <stdio.h>
#include <sys/timeb.h>

namespace my_date {
    std::string Date::cur_time() {
        struct timeb tp;
        ftime(&tp);
        struct tm* time_now = localtime(&tp.time);
        char buffer[128] = { 0 };
        sprintf(buffer, 
                "%d-%d-%d %d:%d:%d,%d",
                time_now->tm_year + 1900,
                time_now->tm_mon + 1,
                time_now->tm_mday,
                time_now->tm_hour,
                time_now->tm_min,
                time_now->tm_sec,
                tp.millitm
               );
        return buffer;
    }

    bool Date::set_year(const std::string& year) {
        _year = year;
    }
    std::string Date::get_year() {
        return _year;
    }

    bool Date::set_date(Date* date) {
        _date = date;
    }

    Date* Date::get_date() {
        return _date;
    }
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
