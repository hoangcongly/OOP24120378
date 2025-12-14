#include "SoPhuc.h"

int main()
{
    SoPhuc sp1;
    SoPhuc sp2(5, 10);
    SoPhuc sp3(sp1);
    SoPhuc sp4 = sp2.Cong(sp1);
    cout << SoPhuc::SSoLuongSP() << endl;
    {
        SoPhuc sp5;
        SoPhuc sp6 = sp2.Cong(sp4);
    }
    cout << sp4.SoLuongSP() << endl;
    cout << SoPhuc::SSoLuongSP() << endl;

    system("pause");
}