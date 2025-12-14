#pragma once
#include <iostream>

class Date
{
public:
    int day;
    static int current_mock_day;

    Date(int d = 1) : day(d) {}
    static Date get_current_date
    {
        return Date(current_mock_day);
    }

    friend std::ostream &operator<<(std::ostream &os, const Date &d)
    {
        os << "Day " << d.day;
        return os;
    }
};
int Date::current_mock_day = 1;
