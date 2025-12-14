#include <iostream>
using namespace std;

int daysInMonth(int th, int n)
{
    int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (th == 2 && ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0))
        return 29;
    return md[th];
}

class Ngay
{
private:
    int _ng, _th, _n;
    void chuanHoa()
    {
        while (_th > 12)
        {
            _th -= 12;
            _n++;
        }
        while (_th < 1)
        {
            _th += 12;
            _n--;
            if (_n < 1)
                _n = 1;
        }
        while (_ng > daysInMonth(_th, _n))
        {
            _ng -= daysInMonth(_th, _n);
            _th++;
            if (_th > 12)
            {
                _th = 1;
                _n++;
            }
        }

        while (_ng <= 0)
        {
            _th--;
            if (_th <= 0)
            {
                _th = 12;
                _n--;
                if (_n <= 0)
                    _n = 1;
            }
            _ng += daysInMonth(_th, _n);
        }
    }

public:
    Ngay() { _ng = _th = _n = 1; }

    Ngay(int ng, int th, int n)
    {
        _ng = ng;
        _th = th;
        _n = n;
        chuanHoa();
    }

    Ngay(int ng)
    {
        _ng = ng > 0 ? ng : -ng;
        _th = _n = 1;
        chuanHoa();
    }

    Ngay operator+(const Ngay &b) const
    {
        Ngay kq(_ng + b._ng, _th + b._th, _n + b._n);
        kq.chuanHoa();
        return kq;
    }

    Ngay operator+(int k) const
    {
        Ngay kq(_ng + (k > 0 ? k : -k), _th, _n);
        kq.chuanHoa();
        return kq;
    }

    friend Ngay operator+(int k, const Ngay &a)
    {
        return a + k;
    }

    Ngay operator-(const Ngay &b) const
    {
        Ngay kq(_ng - b._ng, _th - b._th, _n - b._n);
        kq.chuanHoa();
        return kq;
    }

    Ngay operator-(int k) const
    {
        Ngay kq(_ng - (k > 0 ? k : -k), _th, _n);
        kq.chuanHoa();
        return kq;
    }

    friend Ngay operator-(int k, const Ngay &a)
    {
        Ngay kq(k - a._ng, 1 - a._th, 1 - a._n);
        kq.chuanHoa();
        return kq;
    }

    bool operator>(const Ngay &b) const
    {
        if (_n != b._n)
            return _n > b._n;
        if (_th != b._th)
            return _th > b._th;
        return _ng > b._ng;
    }

    friend ostream &operator<<(ostream &os, const Ngay &a)
    {
        os << a._ng << "/" << a._th << "/" << a._n;
        return os;
    }
};

int main()
{
    Ngay n1;
    Ngay n2(2, 10, 2014);
    Ngay n3(-10, 16, 2000);
    Ngay n4(1000);
    Ngay n5 = n2 + n3;
    Ngay n6 = n1 + 5000;
    Ngay n7 = 1234 + n4;
    Ngay n8 = 190 + n6 + n7;
    Ngay n9 = n8 - n6;
    Ngay n10 = 12000 - n9;
    if (n10 > n6)
        n10 = n2 - 1000 + n6;

    cout << n1 << endl
         << n2 << endl
         << n3 << endl
         << n4 << endl;
    cout << n5 << endl
         << n6 << endl
         << n7 << endl
         << n8 << endl;
    cout << n9 << endl
         << n10 << endl;
    system("pause");
}
