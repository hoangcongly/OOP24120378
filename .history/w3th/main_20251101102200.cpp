#include <bits/stdc++.h>
using namespace std;

// trả về số ngày trong tháng `th` của năm `n` (xử lý năm nhuận)
int daysInMonth(int th, int n)
{
    static int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (th == 2)
    {
        if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
            return 29;
    }
    return md[th];
}

class Ngay
{
private:
    int _ng, _th, _n;

    // chuẩn hóa sao cho 1 <= th <= 12, 1 <= ng <= daysInMonth(th,n), năm >= 1
    void chuanHoa()
    {
        // điều chỉnh tháng trước (trường hợp cộng lớn month)
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

        // chuẩn hóa ngày (khi ng quá lớn)
        while (true)
        {
            if (_th < 1)
            {
                _th += 12;
                _n--;
                if (_n < 1)
                    _n = 1;
            }
            int dim = daysInMonth(_th, _n);
            if (_ng > dim)
            {
                _ng -= dim;
                _th++;
                if (_th > 12)
                {
                    _th = 1;
                    _n++;
                }
                continue;
            }
            break;
        }

        // nếu ngày <= 0 thì mượn tháng trước
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

        // cuối cùng bảo đảm tháng và năm hợp lệ
        while (_th > 12)
        {
            _th -= 12;
            _n++;
        }
        if (_n < 1)
            _n = 1;
    }

public:
    // mặc định 1/1/1
    Ngay() : _ng(1), _th(1), _n(1) {}

    // khởi tạo từ (ngay, thang, nam)
    Ngay(int ng, int th, int n) : _ng(ng), _th(th), _n(n)
    {
        chuanHoa();
    }

    // khởi tạo từ 1 số (treat as day count positive)
    Ngay(int ng)
    {
        _ng = (ng >= 0) ? ng : -ng; // theo đề: dùng trị tuyệt đối nếu âm
        _th = 1;
        _n = 1;
        chuanHoa();
    }

    // cộng Ngay + Ngay (cộng tuần tự từng thành phần rồi chuẩn hóa)
    Ngay operator+(const Ngay &b) const
    {
        Ngay r(_ng + b._ng, _th + b._th, _n + b._n);
        r.chuanHoa();
        return r;
    }

    // cộng Ngay + int (int hiểu là số ngày)
    Ngay operator+(int k) const
    {
        Ngay r(_ng + (k >= 0 ? k : -k), _th, _n);
        r.chuanHoa();
        return r;
    }

    // cho phép int + Ngay
    friend Ngay operator+(int k, const Ngay &a)
    {
        return a + k;
    }

    // trừ Ngay - Ngay (theo từng thành phần)
    Ngay operator-(const Ngay &b) const
    {
        Ngay r(_ng - b._ng, _th - b._th, _n - b._n);
        r.chuanHoa();
        return r;
    }

    // Ngay - int (int là số ngày)
    Ngay operator-(int k) const
    {
        Ngay r(_ng - (k >= 0 ? k : -k), _th, _n);
        r.chuanHoa();
        return r;
    }

    // int - Ngay  (ví dụ 12000 - n9 trong main)
    friend Ngay operator-(int k, const Ngay &a)
    {
        // tạo 1 Ngay từ k rồi trừ a (để tận dụng chuẩn hóa)
        Ngay temp(k);
        return temp - a;
    }

    // so sánh >
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

// --- main giống đề bài ---
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
    {
        n10 = n2 - 1000 + n6;
    }

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
    return 0;
}
