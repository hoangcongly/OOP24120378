#include <iostream>
#include "studentw3.h"
using namespace std;

int main() {
    // Tạo dữ liệu mẫu
    vector<pair<string, pair<int, float>>> sub1 = {
        {"Toan", {3, 8.5}}, {"Ly", {2, 7.0}}, {"Hoa", {3, 9.0}}
    };
    vector<pair<string, pair<int, float>>> sub2 = {
        {"Toan", {3, 6.0}}, {"Ly", {2, 6.5}}, {"Hoa", {3, 5.5}}
    };
    vector<pair<string, pair<int, float>>> sub3 = {
        {"Toan", {3, 9.0}}, {"Ly", {2, 8.5}}, {"Hoa", {3, 9.5}}
    };

    CStudent sv1("Nguyen Van A", "SV001", sub1);
    CStudent sv2("Tran Thi B", "SV002", sub2);
    CStudent sv3("Le Van C", "SV003", sub3);

    CListStudent list({sv1, sv2, sv3});

    cout << "=== Danh sach sinh vien ===\n";
    list.Output();

    cout << "\n=== Sinh vien GPA cao nhat ===\n";
    cout << list.FindMaxGPAStudent() << endl;

    cout << "\n=== Sinh vien GPA thap nhat ===\n";
    cout << list.FindMinGPAStudent() << endl;

    cout << "\n=== Sap xep tang dan theo GPA ===\n";
    list.SortAscending();
    list.Output();

    cout << "\n=== Sap xep giam dan theo GPA ===\n";
    list.SortDescending();
    list.Output();

    cout << "\n=== Bang xep hang sinh vien ===\n";
    list.RankStudent();

    cout << "\n=== Tim sinh vien theo MSSV 'SV002' ===\n";
    cout << list.FindStudent("SV002") << endl;

    cout << "\n=== Xoa sinh vien co MSSV 'SV001' ===\n";
    list.DeleteStudent("SV001");
    list.Output();

    return 0;
}
