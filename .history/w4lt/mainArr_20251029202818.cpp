#include "Array.h"

int main()
{
    cout << " Constructor mac dinh & operator<<" << endl;
    Array a1;
    cout << "a1 (default): " << a1 << endl;

    cout << "\nConstructor voi kich thuoc" << endl;
    Array a2(5);
    cout << "a2 (size 5): " << a2 << endl;

    cout << "\noperator[] (gan gia tri)" << endl;
    for (int i = 0; i < 5; ++i)
    {
        a2[i] = (i + 1) * 10;
    }
    cout << "a2 (sau khi gan): " << a2 << endl;

    cout << "\nConstructor sao chep" << endl;
    Array a3 = a2;
    cout << "a3 (sao chep tu a2): " << a3 << endl;

    cout << "\noperator= " << endl;
    Array a4;
    a4 = a2;
    cout << "a4 (gan tu a2): " << a4 << endl;
    a4 = a1;
    cout << "a4 (gan tu a1): " << a4 << endl;

    cout << "\noperator+= " << endl;
    cout << "a3 (truoc): " << a3 << endl;
    Array a5(3);
    a5[0] = 100;
    a5[1] = 200;
    a5[2] = 300;
    cout << "a5: " << a5 << endl;
    a3 += a5;
    cout << "a3 (sau a3 += a5): " << a3 << endl;

    cout << "\noperator+" << endl;
    Array a6(2);
    a6[0] = 1;
    a6[1] = 2;
    Array a7(3);
    a7[0] = 3;
    a7[1] = 4;
    a7[2] = 5;
    cout << "a6: " << a6 << endl;
    cout << "a7: " << a7 << endl;
    Array a8 = a6 + a7;
    cout << "a8 (a6 + a7): " << a8 << endl;

    cout << "\n--- Test 8: Chuyen doi sang int* ---" << endl;
    cout << "a8 (truoc): " << a8 << endl;
    int *p_a8 = a8;
    p_a8[0] = 999;
    cout << "a8 (sau khi thay doi qua con tro): " << a8 << endl;

    cout << "\noperator>> " << endl;
    Array a9;
    cout << "Vui long nhap mot mang cho a9:" << endl;
    cin >> a9;
    cout << "Ban da nhap a9: " << a9 << endl;

    cout << "\nKiem tra truy cap ngoai pham vi" << endl;

    cout << "Truy cap hop le a2[3]: " << a2[3] << endl;

    cout << "\ntruy cap a2[10] (ngoai pham vi)" << endl;

    cout << a2[10];
    return 0;
}