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
//Tìm mã số được nhiều người bình chọn nhất, và số 
//lượt bình chọn cho tin nhắn này, trả ra file giống 
//tập tin output mẫu. 
void CListMessage:: GetMostVotedCode()
{
    if(m_Message.empty())
    {
        cout << "Danh sach tin nhan trong!" << endl;
        return;
    }
    map<int, int> voteCount;// map(mavote, so luot)
    for(const CMessage& mes: m_Message)
    {
        voteCount[mes.getVote()]++;
    }
    int mostVotedCode=-1;
    int maxVote=0;
    for(const auto&pair:voteCount)
    {
        if(pair.second>maxVote)
        {
            maxVote=pair.second;
            mostVotedCode=pair.first;// ma vote tuong ung voi cai nhieu nhat
        }
    }
    ofstream outFile("output.txt");
    if(!outFile)
    {
        cerr << "Khong mo duoc file" << endl;
        return;
    }
    outFile << "Ma so: " << mostVotedCode << endl;
    outFile << "So luot binh chon: " << maxVote << endl;
}
//Tìm số điện thoại nhắn tin nhiều nhất, in ra màn hình. 
string CListMessage:: GetMostActivePhone()
{
    if(m_Message.empty())
    {
        return "";
    }
    map<int, int> phoneCount;
    for(const CMessage& mes:m_Message)
    {
        phoneCount[mes.getNumber()]++;
    }
    int activePhone=-1;
    int maxCount=0;
    for(const auto& pair: phoneCount)
    {
        if(pair.second>maxCount)
        {
            maxCount=pair.second;
            activePhone=pair.first;
        }
    }
    return to_string(activePhone);
}
//Tìm ngày có nhiều người nhắn tin nhất, in ra màn hình. 
CMyDate CListMessage::GetPeakMessageDay()
{
    if(m_Message.empty())
    {
        return {1,1,1970};
    }
    map<CMyDate,int> dayCount;
    for(const CMessage& mes: m_Message)
    {
        dayCount[mes.getDate()]++;
    }
    CMyDate peakDay={1,1,1970};
    int maxMessages=0;
    for(const auto&pair: dayCount)
    {
        if(pair.second>=maxMessages)
        {
            maxMessages= pair.second;
            peakDay= pair.first();
        }
    }
    return peakDay;
}

//Tìm thời điểm có nhiều người bình chọn nhất, in ra màn hình.
CMyTime CListMessage:: GetPeakVotingTime()
{
    if(m_Message.empty())
    {
        return {0,0,0};
    }
    map<CMyTime,int> timeCount;
    for(const CMessage&mes: m_Message)
    {
        timeCount[mes.getTime()]++;
    }
    CMyTime peakTime= {0,0,0};
    int maxMessages=0;
    for(const auto& pair: timeCount)
    {

    }
}