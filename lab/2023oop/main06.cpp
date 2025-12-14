#include "mesw6.h"
using namespace std;

int main()
{
    CListMessage list;

    ifstream fin("input06.txt");
    if (!fin)
    {
        cout << "Khong mo duoc file input.txt\n";
        return 1;
    }

    fin >> list;
    fin.close();

    cout << "=== DANH SACH TIN NHAN ===\n";
    cout << list;

    cout << "\n=== MA SO DUOC BINH CHON NHIEU NHAT ===\n";
    list.GetMostVotedCode();

    cout << "\n=== SO DIEN THOAI GUI NHIEU NHAT ===\n";
    cout << list.GetMostActivePhone() << endl;

    cout << "\n=== NGAY CO NHIEU TIN NHAN NHAT ===\n";
    CMyDate peakDate = list.GetPeakMessageDay();
    cout << peakDate.m_Day << "/" << peakDate.m_Month << "/" << peakDate.m_Year << endl;

    cout << "\n=== THOI GIAN BINH CHON NHIEU NHAT ===\n";
    CMyTime peakTime = list.GetPeakVotingTime();
    cout << peakTime.m_Hour << ":" << peakTime.m_Minute << ":" << peakTime.m_Second << endl;

    cout << "\n=== TOP 10 MA SO DUOC BINH CHON NHIEU NHAT ===\n";
    list.Top10();

    return 0;
}