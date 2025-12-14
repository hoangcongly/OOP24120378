#include "date.h"
int CDate:: DaysInMonth(int m, int y)
{
    static int days[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2&& InspectLeapYear()) return 29;
    return days[m-1]; 
}
void CDate:: InputDate()
{
    cout << "Nhap ngay thang nam: ";
    cin >> day >> month >> year;
}
void CDate:: OutputDate()
{
    cout << setw(2) << setfill('0') << day << "/"
         << setw(2) << setfill('0') << month << "/"
         << year << endl;
}
bool CDate:: CheckDate()
{
    if(year<0) return false;
    if(month<1|| month>12) return false;
    if(day<1 || day> DaysInMonth(month, year)) return false;
    return true;
}
bool CDate:: InspectLeapYear(int y)
{
    if((y%400==0) || (y%4==0 && y%100!=0)) return true;
    return false;
}
bool CDate:: InspectLeapYear()
{
    return InspectLeapYear(year);
}
CDate CDate:: IncreaseYear()
{
    return IncreaseYear(1);
}
CDate CDate:: IncreaseMonth()
{
    return IncreaseMonth(1);
}
CDate CDate:: IncreaseDay()
{
    return IncreaseDay(1);
}
CDate CDate:: DecreaseYear()
{
    return DecreaseYear(1);
}
CDate CDate:: DecreaseMonth()
{
    return DecreaseMonth(1);
}
CDate CDate:: DecreaseDay()
{
    return DecreaseDay(1);
}
CDate CDate:: IncreaseYear(int n)
{
    year += n;
    if(day > DaysInMonth(month, year)) 
        day = DaysInMonth(month, year);
    return *this;
}
CDate CDate:: IncreaseMonth(int n)
{
    month+=n;
    while(month>12)
    {
        month-=12;
        year++;
    }
    if(day>DaysInMonth(month,year)) day= DaysInMonth(month, year);
    return *this;
}
CDate CDate:: IncreaseDay(int n)
{
    day+=n;
    while(day> DaysInMonth(month, year))
    {
        day-=DaysInMonth(month, year);
        IncreaseMonth(1);
    }
    return *this;
}
CDate CDate:: DecreaseYear(int n)
{
    if(year-n>0) year-=n; 
    return *this;
}
CDate CDate:: DecreaseMonth(int n)
{
    month-=n;
    while(month<1)
    {
        month+=12;
        DecreaseYear(1);
    }
    if(day> DaysInMonth(month,year)) day= DaysInMonth(month, year);
    return *this;
}
CDate CDate:: DecreaseDay(int n)
{
    day-=n;
    while(day<1)
    {
        DecreaseMonth(1);
        day+=DaysInMonth(month,year);
    }
    return *this;
}
int CDate::DayOrderInYear()
{
    int result= day;
    for(int m=1; m < month; m++)
    {
        result+= DaysInMonth(m, year); 
    }
    return result;
}
int CDate:: WeekOrderInYear()
{
    int dayOrder = DayOrderInYear();   // thứ tự ngày trong năm
    int weekOrder = (dayOrder - 1) / 7 + 1; // tuần bắt đầu từ ngày 1
    return weekOrder;
}
void CDate:: ConvertDate()
{
    static string monthName[12]={"January","February","March","April","May","June",
        "July","August","September","October","November","December"};
    cout << monthName[month-1] << " " << day << ", " << year;
}
int CDate::ToDays()
{
    int total = 0;
    // cộng đủ số ngày của các năm trước
    for(int y = 1; y < year; y++) {
        total += (InspectLeapYear(y) ? 366 : 365);
    }
    // cộng số ngày của các tháng trước trong năm hiện tại
    for(int m = 1; m < month; m++) {
        total += DaysInMonth(m, year);
    }
    // cộng số ngày trong tháng hiện tại
    total += day;
    return total;
}
int CDate:: DeductDateToDate(CDate d2)
{
    return abs(this->ToDays() - d2.ToDays());
}
