/*
Áp dụng kiến thức đã học , xây dựng lớp đối tượng sao cho chỉ tồn tại nhiều nhất một đối tượng có kiểu dữ liệu trả về là lớp này trong chương trình 
*/
#include "Singleton.h"

int main()
{
    Singleton*s1= Singleton:: getInstance();
    Singleton*s2= Singleton:: getInstance();
    s1->showMessage();
    cout << "Dia chi s1: " << s1 << endl;
    cout << "Dia chi s2: " << s2 << endl;

    return 0;
}