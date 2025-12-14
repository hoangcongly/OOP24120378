#include <iostream>
using namespace std;

class lopA{ // khai báo lớp cơ sở lopA
public:
    lopA();
    virtual void logging();// hàm ảo
};

class lopB: public lopA{ // khai báo lớp kế thừa lopB
public:
    lopB(){};
    void logging();
};

lopA::lopA() // Phương thức tạo lập mặc định cho lớp A
{
    logging();
}
void lopA:: logging()
{
    cout << " Phuong thuc logging cua lop A" << endl;
}
void lopB:: logging()
{
    cout << " Phuong thuc logging cua lop B" << endl;
}
int main()
{
    lopB b;
    return 0;
}