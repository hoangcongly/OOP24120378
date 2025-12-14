/*
Quản lý tài khoản ngân hàng Lớp Account: mã số, tên chủ tài khoản, số dư.
 Lớp con: SavingAccount: có lãi suất, hạn gửi. 
 CheckingAccount: có phí giao dịch. 
 Yêu cầu: Nạp, rút tiền (kiểm tra hợp lệ). 
 Tính lãi suất định kỳ cho tài khoản tiết kiệm. 
 In sao kê tài khoản. 
 Giao dịch chuyển tiền giữa hai tài khoản. 
 Yêu cầu sử dụng: con trỏ đối tượng, virtual function, dynamic_cast (nếu cần).
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
private:
    string id;
    string owner;
    float balance;
public:
    Account(string _id, string _owner, float _balance)
    {
        id=_id;
        owner= _owner;
        balance= _balance;
    }
    
};