#include <iostream>
using namespace std;

class lopA{ // khai báo lớp cơ sở lopA
public:
    lopA()
    {
        logging();
    }
    virtual void logging()// hàm ảo
    {
        cout << " Phuong thuc logging cua lop A" << endl;
    }
};

class lopB: public lopA{ // khai báo lớp kế thừa lopB
public:
    lopB(){};
    void logging() override
    {
        cout << " Phuong thuc logging cua lop B" << endl;
    }
};


int main()
{
    lopB b;
    return 0;
}