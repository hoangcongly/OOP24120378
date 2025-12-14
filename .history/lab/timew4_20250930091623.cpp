#include "timew4.h"

CMyTime:: CMyTime() 
{
    m_Hour=0; 
    m_Minute=0;
    m_Second=0;
}
CMyTime:: CMyTime(const CMyTime&other)
{
    m_Hour= other.m_Hour;
    m_Minute= other.m_Minute;
    m_Second= other.m_Second;
}
CMyTime:: CMyTime(int hour, int min, int sec)
{
    m_Hour= hour;
    m_Minute= min;
    m_Second= sec;
}
void CMyTime:: Normalize()
{
    if(m_Second>=60)
    {
        m_Minute+=m_Second/60;
        m_Second%=60;
    }
    if(m_Minute>=60)
    {
        m_Hour+=m_Minute/60;
        m_Minute%=60;
    }
    if(m_Second<0)
    {
        m_Second+=60;
        m_Minute--;
    }
    if(m_Minute<0)
    {
        m_Minute+=60;
        m_Hour--;
    }
    if(m_Hour<0) m_Hour=0;
}
istream& operator>>(istream& in, CMyTime& t) {
    in >> t.m_Hour;
    in >> t.m_Minute;
    in >> t.m_Second;
    return in;
}
ostream& operator<<(ostream&out, const CMyTime&t)
{
    out << t.m_Hour << ":" << t.m_Minute << ":" << t.m_Second << endl;
}
CMyTime CMyTime:: operator++()
{
    m_Second++;
    Normalize();
    return*this;
}
CMyTime CMyTime:: operator--(int minute)
{
    CMyTime temp(*this);
    m_Minute--;
    Normalize();
    return temp;
}
CMyTime CMyTime:: operator+=(int hour)
{
    m_Hour+=hour;
    Normalize();
    return*this;
}
CMyTime CMyTime:: operator-=(int hour)
{
    m_Hour-=hour;
    Normalize();
    return*this;
}
CMyTime CMyTime:: operator+(const CMyTime&other) const
{
    return CMyTime(m_Hour+other.m_Hour, m_Minute+other.m_Minute, m_Second+other.m_Second);
}
CMyTime CMyTime:: operator-(const CMyTime&other) const
{
    return CMyTime(m_Hour-other.m_Hour, m_Minute-other.m_Minute, m_Second-other.m_Second);
}
bool CMyTime:: operator>(const CMyTime& other) const
{
    if(m_Hour!=other.m_Hour) return m_Hour>other.m_Hour;
    if(m_Minute!=other.m_Minute) return m_Minute>other.m_Minute;
    return m_Second> other.m_Second;
}
bool CMyTime:: operator<(const CMyTime&other) const
{
    return other>*this;
}
bool CMyTime:: operator>=(const CMyTime&other) const
{
    return !(*this<other);
}
bool CMyTime:: operator<=(const CMyTime&other) const
{
    return !(*this>other);
}
bool CMyTime:: operator==(const CMyTime&other) const
{
    return m_Hour== other.m_Hour&& m_Minute== other.m_Minute&& m_Second== other.m_Second;
}
void CMyTime:: Display() 
{
        cout << setfill('0') << setw(2) << m_Hour << ":"
             << setw(2) << m_Minute << ":"
             << setw(2) << m_Second;
    }
 void CMyTime:: ShowTime() 
 {
    while (true) 
    {
        system("cls");
        Display();
        Sleep(1000);
        m_Second++;
        Normalize();
    }
}
void CMyTime:: CountDown() {
    while (m_Hour > 0 || m_Minute > 0 || m_Second > 0) {
        system("cls");
        Display();

        Sleep(1000);
        m_Second--;

        if (m_Second < 0) {
            m_Second = 59;
            m_Minute--;
            if (m_Minute < 0) {
                m_Minute = 59;
                m_Hour--;
            }
        }

        if (_kbhit()) {
            char c = _getch();
            if (c == ' ') { // pause
                while (true) {
                    if (_kbhit()) {
                        char c2 = _getch();
                        if (c2 == 13) break; // Enter -> tiếp tục
                    }
                }
            }
        }
    }
    system("cls");
    cout << "00:00:00\n";
}

// 3. Stopwatch: bấm giờ
void CMyTime:: Stopwatch() {
    m_Hour = m_Minute = m_Second = 0;
    bool running = false;
    bool stop = false;

    while (!stop) {
        system("cls");
        Display();
        cout << "\n(s=start, p=pause, r=resume, l=lap, t=stop, esc=reset)\n";

        if (running) {
            Sleep(1000);
            m_Second++;
            Normalize();
        }

        if (_kbhit()) {
            char c = _getch();
            if (c == 's') running = true;
            else if (c == 'p') running = false;
            else if (c == 'r') running = true;
            else if (c == 'l') {
                cout << "\nLap: ";
                Display();
                cout << "\n";
                system("pause");
            }
            else if (c == 't') {
                running = false;
                stop = true;
            }
            else if (c == 27) { // ESC reset
                m_Hour = m_Minute = m_Second = 0;
                running = false;
            }
        }
    }
    cout << "\nTong thoi gian: ";
    Display();
    cout << "\n";
}