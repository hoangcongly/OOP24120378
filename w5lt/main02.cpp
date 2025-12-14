#include "screenVIP.h"

int main()
{
    screenVIP vip(60, 100000, 0.5); // 60 ghế, vé gốc 100k, phụ thu 50%
    vip.addService("Recliners");
    vip.addService("Free Snacks");

    vip.bookSeat(0);
    vip.bookSeat(1);
    vip.bookSeat(2);

    vip.printInfo();
    cout << "Doanh thu hien tai: " << vip.totalRevenue() << " VND\n";

    return 0;
}
