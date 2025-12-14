#pragma
#include <iostream>
#include "Vehicle.h"

class Car : public Vehicle
{
private:
    int seating_capacity;

public:
    Car(std::string make, std::string model, std::string license_plate, int cap)
        : Vehicle(make, model, license_plate, 40.0), seating_capacity(cap) {}
    double get_rent_cost(Date start, Date end) const override
    {
        ////////
    }
};
