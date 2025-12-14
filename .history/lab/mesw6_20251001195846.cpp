#include "mesw6.h"

CMessage:: CMessage()
{
    m_Number=0;
    m_Vote=0;
    m_Date={1,1,2000};
    m_Time={0,0,0};
};
CMessage:: CMessage(int number, int vote, CMyDate date, CMyTime time)
{
    m_Number=number;
    m_Vote= vote;
    m_Date=date;
    m_Time=time;
}
istream& operator >> (istream&in, CMessage&mes)
{
    char c;
    in >> mes.m_Number >> mes.m_Vote >> c >> mes.m_Date.m_Day >> c 
        >> mes.m_Date.m_Month >> c >> mes.m_Date.m_Year 
        >> mes.m_Time.m_Hour >> c >> mes.m_Time.m_Minute >> c >> mes.m_Time.m_Second;
    return in;
}
ostream& operator << (ostream&out, const CMessage&mes)
{
    out << mes.m_Number << " "
        << mes.m_Vote << " "
        << (mes.m_Date.m_Day < 10 ? "0" : "") << mes.m_Date.m_Day << "/"
        << (mes.m_Date.m_Month < 10 ? "0" : "") << mes.m_Date.m_Month << "/"
        << mes.m_Date.m_Year << " "
        << (mes.m_Time.m_Hour < 10 ? "0" : "") << mes.m_Time.m_Hour << ":"
        << (mes.m_Time.m_Minute < 10 ? "0" : "") << mes.m_Time.m_Minute << ":"
        << (mes.m_Time.m_Second < 10 ? "0" : "") << mes.m_Time.m_Second;
    return out;
}
istream& operator >> (istream&in, CListMessage&listmes)
{
    listmes.m_Message.clear();
    CMessage mes;
    while(in >> mes)
    {
        listmes.m_Message.push_back(mes);
    }
    return in;
}
ostream& operator << (ostream& out, const CListMessage& listmes)
{
    for(CMessage mes: listmes.m_Message)
    {
        out << mes << endl;
    }
    return out;
}
int CMessage::getNumber() const 
{
    return m_Number;
}
int CMessage::getVote() const
{
    return m_Vote;
}
CMyDate CMessage::getDate() const 
{
    return m_Date;
}
CMyTime CMessage::getTime() const
{
    return m_Time;
}
int CListMessage:: GetMostVotedCode()
{
    if(m_Message.empty()) return -1;
    map<int, int> voteCount;
    for(const auto& mes: m_Message)
    {
        voteCount[mes.getVote()]++;
    }
    int maxvote=0;
    int resultcode=-1;
    for(const auto&pair: voteCount)
    {
        if(pair.second>maxvote)
        {
            maxvote=pair.second;
            resultcode=pair.first;
        }
    }
    return resultcode;
}
string CListMessage:: GetMostActivePhone()
{
    if(m_Message.empty()) return "";
    map<int, int> phoneCount;
    for(const auto&mes: m_Message)
    {
        phoneCount[mes.getNumber()]++;
    }
    int maxcount=0;
    int activePhone=-1;
    for(const auto& pair: phoneCount)
    {
        if(pair.second>maxcount) 
        {
            maxcount=pair.second;
            activePhone=pair.first;
        }
    }
    return to_string(activePhone);
}
CMyDate CListMessage:: GetPeakMessageDay()
{
    
}