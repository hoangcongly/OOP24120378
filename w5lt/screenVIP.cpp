#include "screenVIP.h"

screenVIP::screenVIP(): screen()
{
    extraChargeRate=0.2;
}

screenVIP:: screenVIP(const int&totalSeat, const double& basePrice, const double& rate): screen(totalSeat, basePrice)
{
    extraChargeRate= rate;
}

void screenVIP::addService(const string& service)
{
    extraService.push_back(service);
}

double screenVIP::calcPrice()
{
    return basePrice*(1+extraChargeRate);
}

void screenVIP:: printInfo()
{
    cout << "Loai phong: VIP Screen\n";
    cout << "Tong so ghe: " << totalSeat << endl;
    cout << "Gia ve co phu thu: " << calcPrice() << " VND\n";
    cout << "Dich vu kem theo: ";
    for (const auto& s : extraService)
        cout << s << " ";
    cout << "\n";
}

double screenVIP::totalRevenue()
{
    int booked=0;
    for (int i = 0; i < totalSeat; i++)
    {
        if (seats[i])
            booked++;
    }
    return booked * calcPrice();    
}