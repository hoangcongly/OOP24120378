#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
using namespace std;

static int numMax=0;
class Object
{
private: 
    int info;
    int curNum;
public: 
    Object();
    Object(int value);
    ~Object();
};

void Create(); 
#endif //OBJECT_H