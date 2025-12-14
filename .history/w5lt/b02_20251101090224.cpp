#include "b02.h"

Client::Client(string n, string ID)
{
    name = n;
    clientID = ID;
}

void Client::display() const
{
    cout << "Client name: " << name << endl
         << "Client ID: " << clientID << endl;
}

Account::Account(Client cl, int ac_num, double bal)
{
    client = cl;
    account_number = ac_num;
    balance = bal;
}

double Account::getBalance() const
{
    return balance;
}

void Account::deposit(double amount)
{
    balance += amount;
}

void Account::withdraw(double amount)
{
    balance -= amount;
    if (balance < 0)
        balance = 0;
}

void Account::display() const
{
    client.display();
    cout << "Account number: " << account_number << endl
         << "Balance: " << balance << endl;
}

SavingAccount::SavingAccount(Client cl, int accnum, double bal, float rate): Account(cl, accnum, bal)
{
    interest_rate= rate;
}

void SavingAccount:: applyInterest()
{
    
}