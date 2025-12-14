#pragma
#include <iostream>
#include <string.h>
#include <vector>

class BenhNhan
{
private:
    std::string m_msbn;
    std::string m_hoTen;

public:
    BenhNhan(const std::string &msbn, const std::string &hoTen) : m_msbn(msbn), m_hoTen(hoTen) {}
    virtual ~BenhNhan() = default;
    virtual double TinhVienPhi() const = 0;
    std::string getMSBN() const { return m_msbn; }
    std::string getHoTen() const { return m_hoTen; }
    virtual void XuatThongTin() const
    {
        std::cout << "MSBN: " << m_msbn
                  << " - Ho ten: " << m_hoTen;
    }
};
