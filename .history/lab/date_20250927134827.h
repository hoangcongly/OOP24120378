#ifndef CDATE_H
#define CDATE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;

class CDate{
private:
    int year;
    int month;
    int day;
public:
    int DaysInMonth(int m, int year);
    void InputDate();
    void OutputDate();
    bool CheckDate();
    bool InspectLeapYear();
    bool InspectLeapYear(int y);
    CDate IncreaseYear();
    CDate IncreaseMonth();
    CDate IncreaseDay();
    CDate DecreaseYear();
    CDate DecreaseMonth();
    CDate DecreaseDay();
    CDate IncreaseYear(int n);
    CDate IncreaseMonth(int n);
    CDate IncreaseDay(int n);
    CDate DecreaseYear(int n);
    CDate DecreaseMonth(int n);
    CDate DecreaseDay(int n);
    int DayOrderInYear();
    int WeekOrderInYear();
    void ConvertDate();
    int CDate::ToDays();
    int DeductDateToDate(CDate d2);
};

#endif CDATE_H