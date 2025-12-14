#ifndef B02_H
#define B02_H

#include <iostream>
using namespace std;

class Client
{
private:
    string name;
    string clientID;

public:
    void display();
};

class Account
{
private:
    Client Client;
    int account_number;
    double balence;

public:
};
#endif