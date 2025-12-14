#pragma
#include <iostream>
#include <string.h>
#include "Date.h"

class Vehicle
{
protected:
    std::string make;
    std::string model;
    std::string license_plate; // bien so xe
    double daily_rate;         // don gia thue moi ngay
    Date start_date;
    std::string customer_id;
    bool is_rented;
s

    public : Vehicle(std::string make, std::string model, std::string license_plate, double rate) : make(make), model(model), license_plate(license_plate), daily_rate(rate), is_rented(false)
    {
    }
    virtual ~Vehicle();
    std::string get_license_plate() const { return license_plate; }
    Date get_start_date() const { return start_date; }
    bool is_available() const
    {
        return !is_rented;
    }
    virtual void rent()
    {
        rent("UNKNOWN_CUSTOMER");
    }
    virtual void rent(std::string cus_id)
    {
        if (is_rented)
        {
            std::cout << "Error: Vehicle " << license_plate << " is already rented" << std::endl;
            return;
        }
        this->is_rented = true;
        this->customer_id = cus_id;
        this->start_date = Date::get_current_date();
        std::cout << "Vehicle " << license_plate << " rented by " << customer_id
                  << " on " << start_date << std::endl;
    }

    virtual void return_vehicle()
    {
        if (!is_rented)
        {
            std::cout << "Error: Vehicle " << license_plate << " is not currently rented." << std::endl;
            return;
        }
        this->is_rented = false;
    }
    virtual double get_rent_cost(Date start, Date end) const = 0;
};
