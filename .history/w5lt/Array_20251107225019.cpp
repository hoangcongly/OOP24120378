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
        data= new int[size];
        for(int i=0; i<size; i++)
        {
            data[i]=0; 
        }
    }
}

Array::~Array()
{
    delete[] data;
    size=0;
}

Array::Array(const Array&other)
{
    
}