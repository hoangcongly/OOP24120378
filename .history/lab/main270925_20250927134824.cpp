#include <iostream>
#include "date.h"
using namespace std;

int main() {
    CDate d1, d2;

    cout << "Nhap ngay thang nam thu nhat:\n";
    d1.InputDate();
    cout << "Nhap ngay thang nam thu hai:\n";
    d2.InputDate();

    cout << "\n--- Ket qua ---\n";
    cout << "Ngay 1: "; d1.OutputDate();
    cout << "Ngay 2: "; d2.OutputDate();

    cout << "Hop le ngay 1? " << (d1.CheckDate() ? "Dung" : "Sai") << endl;
    cout << "Hop le ngay 2? " << (d2.CheckDate() ? "Dung" : "Sai") << endl;

    cout << "Thu tu ngay trong nam cua ngay 1: " << d1.DayOrderInYear() << endl;
    cout << "Thu tu tuan trong nam cua ngay 1: " << d1.WeekOrderInYear() << endl;

    cout << "Dinh dang chu cua ngay 1: "; d1.ConvertDate(); cout << endl;

    cout << "So ngay giua ngay 1 va ngay 2: " << d1.DeductDateToDate(d2) << endl;

    cout << "\nTang ngay 1 len 10 ngay: ";
    d1.IncreaseDay(10).OutputDate();

    cout << "Giam ngay 2 xuong 20 ngay: ";
    d2.DecreaseDay(20).OutputDate();

    return 0;
}
