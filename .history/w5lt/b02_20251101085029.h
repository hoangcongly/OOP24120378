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
    Client(string name = "", string clientID = "");
    void display() const;
};

class Account
{
private:
    Client client;
    int account_number;
    double balance;

public:
    Account(Client cl = Client(), int account_number = 0, double balance = 0);
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    virtual void display() const;
};

class SavingAccount : public Account
{
private:
    float interest_rate;

public:
    SavingAccount(Client cl = Client(), int accnum = 0, double bal = 0, float rate = 0.0f);
    void applyInterest();
    void display() const override;
};
#endif