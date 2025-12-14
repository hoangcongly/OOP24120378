#include "Object.h"

Object:: Object()
{
    info=0;
    curNum=++numMax;
    cout << "Khoi tao (mac dinh) doi tuong " << curNum << endl;
}
Object:: Object(int value)
{
    info=value;
    curNum=++numMax;
    cout << "Khoi tao (co doi so) doi tuong " << curNum << endl;
}
Object::~Object()
{
    cout << "Huy doi tuong " << curNum << endl;
}
void Create()
{
    Object obj1(5);
    Object obj2;
}
Object objGlobal;