#include "b02.h"

int main()
{
    Client client1("Nguyen Van An", "VN001");
    Client client2("Tran Thi Binh", "VN002");
    cout << "--- THONG TIN TAI KHOAN THUONG ---" << endl;
    Account accNormal(client1, 1001, 5000000.0);
    accNormal.display();
    cout << "\nThuc hien giao dich voi Tai khoan thuong:" << endl;
    double depositAmount = 2000000.0;
    cout << " Nap them: " << depositAmount << " VND" << endl;
    accNormal.deposit(depositAmount);
    double withdrawAmount = 1500000.0;
    cout << " Rut bot: " << withdrawAmount << " VND" << endl;
    accNormal.withdraw(withdrawAmount);
    cout << "\ntai khoan thuong sau khi giao dich" << endl;
    accNormal.display();
    cout << "Thong tin tai khoan tiet kiem(ban dau)" << endl;
    SavingAccount accSaving(client2, 2002, 10000000.0, 0.05);
    accSaving.display();
    cout << "\nThuc hien giao dich va tinh lai suat voi Tai khoan tiet kiem:" << endl;
    double savingDeposit = 3000000.0;
    cout << "Nap them: " << savingDeposit << " VND" << endl;
    accSaving.deposit(savingDeposit);
    cout << " Ap dung lai suat (" << accSaving.interest_rate * 100 << "%)" << endl;
    accSaving.applyInterest();
    cout << "\ntai khoan tiet kiem sau khi tinh lai" << endl;
    accSaving.display();

    return 0;
}
