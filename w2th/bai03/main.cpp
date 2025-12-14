#include "HocSinh.h"

int main()
{
    HocSinh hs1;
    hs1.DatHoTen("Nguyen Van A");
    hs1.GanDiem(7, 8, 10);
    HocSinh hs2("Tran Thi B", 5, 8, 4.5);
    HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
    HocSinh hs4("Le Van D", 7.5, 9, -10);
    hs1.In(cout);
    cout << endl;
    hs2.In(cout);
    cout << endl;
    hs3.In(cout);
    cout << endl;
    hs4.In(cout);
    cout << endl;
    cout << "Hoc sinh co diem TB cao nhat:" << endl;
    HocSinh::HSDiemTBCaoNhat()->In(cout);
    cout << endl;
    system("pause");

    return 0;
}