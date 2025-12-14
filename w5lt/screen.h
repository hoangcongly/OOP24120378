#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

class screen
{
private:
    int totalSeat;
    bool* seats;
    double basePrice;
public:
    screen();
    screen(const int& tS, const double&basePrice);
    virtual ~screen();
    bool isSeatAvailable(int seatNumber);
    virtual double calcPrice();
    void bookSeat(int seatNumber);
    virtual void printInfo();
    virtual double totalRevenue();
};

