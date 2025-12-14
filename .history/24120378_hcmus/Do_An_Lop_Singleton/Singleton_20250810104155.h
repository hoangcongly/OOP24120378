#ifndef _Singleton_h
#define _Singleton_h

#include <iostream>

using namespace std;

class Singleton
{
private:
    static Singleton* instance;
    Singleton() {};
    Singleton(const Singleton&) = delete;// xoa copy constructor
    Singleton& operator=(const Singleton&) = delete;// xoa operator =
public:
    static Singleton* getInstance();
    void showMessage();
};

#endif