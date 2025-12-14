#include "Array.h"

Array::Array()
{
    data=nullptr;
    size=0;
}

Array::Array(int s):Array()
{
    size= (s>0)? s:0;
    if(size!=0)
    {

    }
}