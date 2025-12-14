// --- phần đầu file: include, arrNgayCuaThang, LaNamNhuan giữ nguyên ---
#include "ngay.h"
#include <iostream>
using namespace std;

int Ngay::arrNgayCuaThang[][13] = {
    {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool Ngay::LaNamNhuan(const int &n)
{
    return (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0));
}

Ngay::Ngay()
{
    _ng = _th = _n = 1;
}

// Constructor từ số thứ tự ngày (1 -> 1/1/1, 1000 -> 27/9/3)
Ngay::Ngay(const int &n)
{
    int ngay = (n > 0) ? n : -n;
    _n = 1;
    _th = 1;
    _ng = 1;

    // bỏ các năm hoàn chỉnh
    while (ngay > (LaNamNhuan(_n) ? 366 : 365))
    {
        ngay -= (LaNamNhuan(_n) ? 366 : 365);
        _n++;
    }
    // bỏ các tháng trong năm đó
    int idx = LaNamNhuan(_n);
    while (ngay > arrNgayCuaThang[idx][_th])
    {
        ngay -= arrNgayCuaThang[idx][_th];
        _th++;
        idx = LaNamNhuan(_n);
    }
    _ng = ngay;
}

// Constructor từ (d,m,y) -> sẽ gọi chuẩn hoá
Ngay::Ngay(const int &ng, const int &th, const int &n)
{
    _ng = ng;
    _th = th;
    _n = n;
    ChuanHoaNgay();
}

Ngay::~Ngay() {}

// demSoNgay giữ nguyên (trả về số thứ tự ngày)
int Ngay::demSoNgay() const
{
    int result = _ng;
    int th = _th - 1;
    int n = _n - 1;
    while (th > 0)
    {
        result += arrNgayCuaThang[LaNamNhuan(n)][th];
        th--;
    }
    while (n > 0)
    {
        result += LaNamNhuan(n) ? 366 : 365;
        n--;
    }
    return result;
}

// ChuanHoaNgay(): **sửa mạnh** để xử lý cả giá trị âm và overflow của ngày/tháng
void Ngay::ChuanHoaNgay()
{
    // chuẩn hoá tháng trước (đưa _th vào [1..12], cập nhật _n tương ứng)
    if (_th > 0)
    {
        // tháng dương có thể overflow nhiều năm
        if (_th > 12)
        {
            int carry = (_th - 1) / 12; // số năm cộng thêm
            _n += carry;
            _th -= carry * 12;
        }
    }
    else
    {
        // tháng âm hoặc <= 0: mượn năm
        while (_th <= 0)
        {
            _th += 12;
            _n--;
        }
    }

    // giờ chuẩn hoá ngày: ngày có thể âm hoặc quá lớn
    // Tránh làm _ng = abs(_ng) — thay vào đó mượn/cho từ tháng liền kề
    // Nếu _ng <= 0: mượn từ tháng trước
    while (_ng <= 0)
    {
        // mượn 1 tháng: giảm tháng, nếu cần giảm năm
        _th--;
        if (_th <= 0)
        {
            _th += 12;
            _n--;
        }
        int idx = LaNamNhuan(_n);
        _ng += arrNgayCuaThang[idx][_th];
    }

    // Nếu _ng quá lớn cho tháng hiện tại: chuyển sang tháng tiếp theo(s)
    int idx = LaNamNhuan(_n);
    while (_ng > arrNgayCuaThang[idx][_th])
    {
        _ng -= arrNgayCuaThang[idx][_th];
        _th++;
        if (_th > 12)
        {
            _th = 1;
            _n++;
        }
        idx = LaNamNhuan(_n);
    }
}

// --- operator+: sửa để hoạt động đúng ---
/*
    Quy ước:
      - Ngay + int  : thêm số ngày -> dùng demSoNgay() + num
      - Ngay + Ngay : giả định là cộng "vector" (d+m+y) rồi chuẩn hóa
*/
Ngay Ngay::operator+(const int &num) const
{
    int total = this->demSoNgay() + num;
    if (total <= 0)
        return Ngay(1); // nếu <=0 thì trả về mốc 1/1/1 hoặc tùy bạn xử lý
    return Ngay(total);
}

Ngay Ngay::operator+(const Ngay &d) const
{
    // cộng từng thành phần rồi chuẩn hóa (hỗ trợ cả thành phần âm trong d)
    Ngay rs;
    rs._ng = _ng + d._ng;
    rs._th = _th + d._th;
    rs._n = _n + d._n;

    rs.ChuanHoaNgay();
    return rs;
}

Ngay Ngay::operator-(const Ngay &d) const
{
    int hieu = this->demSoNgay() - d.demSoNgay();
    if (hieu <= 0)
        return Ngay(1);
    return Ngay(hieu);
}

bool Ngay::operator>(const Ngay &d) const
{
    if (_n != d._n)
        return _n > d._n;
    if (_th != d._th)
        return _th > d._th;
    return _ng > d._ng;
}

Ngay operator+(const int &num, const Ngay &d)
{
    return d + num;
}

Ngay operator-(const int &num, const Ngay &d)
{
    Ngay rs(num);
    return rs - d;
}

ostream &operator<<(ostream &os, const Ngay &d)
{
    os << d._ng << "/" << d._th << "/" << d._n;
    return os;
}
