#ifndef ACOUNT_H
#define ACOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Acount
{
private:
    long long id;
    string username;
    string password;

    static int counter=0;
public:
    Acount();
    
};

#endif