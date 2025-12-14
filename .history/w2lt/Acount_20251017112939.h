#ifndef ACOUNT_H
#define ACOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Acount
{
private:
    static long long id;
    string username;
    string password;

    static int counter=0;
public:
    Acount();
    Acount(string u, string p);
    Acount(const Acount& other);

};

#endif