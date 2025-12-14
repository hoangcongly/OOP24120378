#include "SoNguyenLon.h"

int main()
{
    SoNguyenLon snl1;
    SoNguyenLon snl2("1234567");
    SoNguyenLon snl3(3, 14);
    SoNguyenLon snl4(9, 20);
    SoNguyenLon snl5 = snl3.Tru(snl2);
    SoNguyenLon snl6 = SoNguyenLon::HieuVoiHangSo(45678910, snl2);
    SoNguyenLon snl7 = snl4.Tru(snl3).Cong(123456789);
    snl1.In(cout);
    cout << endl;
    snl2.In(cout);
    cout << endl;
    snl3.In(cout);
    cout << endl;
    snl4.In(cout);
    cout << endl;
    snl5.In(cout);
    cout << endl;
    snl6.In(cout);
    cout << endl;
    snl7.In(cout);
    cout << endl;

    cout << "SoNguyenLon Max:" << endl;
    SoNguyenLon::SNLMAX().In(cout);
    cout << endl;
    system("pause");
    return 0;
}