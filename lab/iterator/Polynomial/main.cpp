#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
    Polynomial<long long> P, Q;
    int choice;

    while (true)
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap da thuc P tu ban phim (dinh dang n dong coef exp)\n";
        cout << "2. Nhap da thuc Q tu ban phim (dinh dang n dong coef exp)\n";
        cout << "3. Doc da thuc P tu file (bieu thuc hoan chinh)\n";
        cout << "4. Doc da thuc Q tu file (bieu thuc hoan chinh)\n";
        cout << "5. Xuat P(x) va Q(x)\n";
        cout << "6. Tinh P+Q, P-Q, P*Q, P/Q, P%Q\n";
        cout << "7. Dao ham P(x)\n";
        cout << "8. Tinh P(k)\n";
        cout << "9. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        if (choice == 9)
            break;

        if (choice == 1)
        {
            cout << "Nhap n, sau do n dong (coef exp) cho P:\n";
            cin >> P;
        }
        else if (choice == 2)
        {
            cout << "Nhap n, sau do n dong (coef exp) cho Q:\n";
            cin >> Q;
        }
        else if (choice == 3)
        {
            char filename[256];
            cout << "Nhap ten file chua bieu thuc P(x): ";
            cin >> filename;
            if (readFromFileExpr(filename, P))
                cout << "Doc P(x) tu file thanh cong!\n";
            else
                cout << "Doc file that bai!\n";
        }
        else if (choice == 4)
        {
            char filename[256];
            cout << "Nhap ten file chua bieu thuc Q(x): ";
            cin >> filename;
            if (readFromFileExpr(filename, Q))
                cout << "Doc Q(x) tu file thanh cong!\n";
            else
                cout << "Doc file that bai!\n";
        }
        else if (choice == 5)
        {
            cout << "P(x) = " << P << "\n";
            cout << "Q(x) = " << Q << "\n";
        }
        else if (choice == 6)
        {
            cout << "P+Q = " << (P + Q) << "\n";
            cout << "P-Q = " << (P - Q) << "\n";
            cout << "P*Q = " << (P * Q) << "\n";

            if (Q.degree() >= 0)
            {
                cout << "P/Q = " << (P / Q) << "\n";
                cout << "P%Q = " << (P % Q) << "\n";
            }
            else
            {
                cout << "Khong the chia vi Q = 0\n";
            }
        }
        else if (choice == 7)
        {
            cout << "P'(x) = " << P.derivative() << "\n";
        }
        else if (choice == 8)
        {
            long long k;
            cout << "Nhap k: ";
            cin >> k;
            cout << "P(" << k << ") = " << P.evaluate(k) << "\n";
        }
        else
        {
            cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}
