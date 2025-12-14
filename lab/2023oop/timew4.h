#ifndef TIME04_H
#define TIME04_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

class CMyTime
{
private: 
    int m_Hour;
    int m_Minute;
    int m_Second;
    void Normalize();
public: 
    CMyTime();
    CMyTime(const CMyTime&other);
    CMyTime(int hour, int min, int sec);
    friend istream& operator >> (istream& in, CMyTime& t);
    friend ostream& operator << (ostream&out, const CMyTime& t);
    CMyTime operator++();
    CMyTime operator--(int);
    CMyTime operator+=(int);
    CMyTime operator-=(int);
    CMyTime operator+(const CMyTime&other) const;
    CMyTime operator-(const CMyTime&other) const;
    bool operator>(const CMyTime&other) const;
    bool operator<(const CMyTime&other) const;
    bool operator>=(const CMyTime&other) const;
    bool operator<=(const CMyTime&other) const;
    bool operator==(const CMyTime&other) const;
    void Display();
    void ShowTime();
    void CountDown();
    void Stopwatch();
};
#endif //TIME04_H