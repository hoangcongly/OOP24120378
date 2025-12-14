#include <iostream>
using namespace std;

class PhanSo{
private:
    int tu, mau;
public:
    PhanSo()
    {
        tu=0;
        mau=1;
    }
    PhanSo(int t)
    {
        tu=t;
        mau=1;
    }
    PhanSo(int t,int m)
    {
        if(m<0)
        {
            t=-t;
            m=-m;
        }
        if(m==0) m=1;
        tu=t;
        mau=m;
    }
    void get()
    {
        cout << tu << "/" << mau << endl;
    }
    void update()
    {
        tu+=1;
        mau+=1;
    }
    //~PhanSo();
};
int main()
{
    PhanSo a;
    a.get();
    PhanSo b(5); 
    b.get();
    PhanSo c(5,3);
    c.get();
    PhanSo d(a);
    d.get();
}

