#include "timew4.h"

int main() {
    CMyTime time;

    int choice;
    do {
        system("cls");
        cout << "===== CHUONG TRINH QUAN LY THOI GIAN =====\n";
        cout << "1. Dong ho tu dong tang thoi gian (ShowTime)\n";
        cout << "2. Dem nguoc thoi gian (CountDown)\n";
        cout << "3. Dong ho bam gio (Stopwatch)\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
        case 1:
            freopen("INPUT.txt", "r", stdin);
            cin >> time;
            fclose(stdin);
            time.ShowTime();
            break;
        case 2:
            freopen("INPUT.txt", "r", stdin);
            cin >> time;
            fclose(stdin);
            time.CountDown();
            break;
        case 3:
            time.Stopwatch();
            break;
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
            system("pause");
        }
    } while (choice != 0);

    return 0;
}
