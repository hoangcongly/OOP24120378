#pragma

#include <iostream>
#include <string>
#include "screen.h"
#include <vector>
using namespace std;
class screenVIP : public screen
{
private:
    double extraChargeRate;
    vector<string> extraService;

public:
    screenVIP();
    screenVIP(const int &totalSeat, const double &basePrice, const double &rate);
    void addService(const string &service);
    double calcPrice() override;
    void printInfo() override;
    double totalRevenue() override;
};
