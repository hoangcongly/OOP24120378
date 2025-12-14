#include "screen.h"

screen::screen()
{
    totalSeat=100;
    basePrice=100.000;
    seats= new bool[totalSeat];
    for(int i=0; i<totalSeat; i++)
    {
        seats[i]=false;
    }
}

screen:: screen(const int&tS, const double& basePrice)
{
    this->totalSeat= tS;
    this->basePrice= basePrice;
    seats= new bool[totalSeat];
    for(int i=0; i<totalSeat; i++)
    {
        seats[i]= false;
    }
}

screen::~screen()
{
    delete[] seats;
}

bool screen:: isSeatAvailable(int seatNumber)
{
    if(seatNumber>=totalSeat|| seatNumber<0)
    {
        throw std:: out_of_range("out of range");
    }
    return !seats[seatNumber];
}

double screen:: calcPrice()
{
    return basePrice;
}

void screen:: bookSeat(int seatNumber)
{
    if(seatNumber>=totalSeat|| seatNumber<0)
    {
        throw std:: out_of_range("out of range");
    }
    if(isSeatAvailable(seatNumber))
    {
        seats[seatNumber]=true;
        std::cout << "Ghe so " << seatNumber << " da duoc dat thanh cong!\n";
    }
    else
    {
        std::cout << "Ghe so " << seatNumber << "da duoc dat!\n";
    }
}

void screen:: printInfo()
{
    std:: cout << "Loai phong: standard Screen\n";
    std:: cout << "Tong so ghe: " << totalSeat << std:: endl;
    std:: cout << "Gia ve tieu chuan: " << basePrice << " VND\n";
}

double screen::totalRevenue()
{
    int booked=0;
    for(int i=0; i<totalSeat; i++)
    {
        if(!isSeatAvailable(i))
        {
            booked+=1;
        }
    }
    return booked*calcPrice();
}