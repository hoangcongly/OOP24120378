#ifndef MESW6_H
#define MESW6_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct CMyDate
{
    int m_Day;
    int m_Month;
    int m_Year;
};
struct CMyTime
{
    int m_Hour;
    int m_Minute;
    int m_Second;
};
class CMessage
{
private:
    int m_Number;
    int m_Vote;
    CMyDate m_Date;
    CMyTime m_Time;
public:
    CMessage(/* args */);
    CMessage(int number, int vote, CMyDate date, CMyTime time);
    ~CMessage();
    friend istream& operator >> (istream&in, CMessage& mes);
    friend ostream& operator << (ostream&out, const CMessage&mes);
};
class CListMessage
{
private:
    vector<CMessage> m_Message;
    int m_Amount;
public:
    CListMessage(/* args */);
    ~CListMessage();
    friend istream& operator >> (istream&in, CListMessage&listmes);
    friend ostream& operator << (ostream&out, CListMessage&listmes);
    void GetMostVotedCode();
    string GetMostActivePhone();
    CMyDate GetPeakMessageDay();
    CMyTime GetPeakVotingTime();
    void Top10();
};

#endif //MESW6_H