#ifndef ARRAYW2_H
#define ARRAYW2_H

#include <iostream>
#include <math.h>
using namespace std;

class CIntArray
{
private:
    int *m_Array;
    int m_Length;
public:
    // Constructor
    CIntArray();
    CIntArray(const CIntArray& other);
    CIntArray(int* arr, int length);
    ~CIntArray();
    // input output
    void InputArray();
    void OutputArray();
    CIntArray Remove();
    CIntArray Remove(int n);
    CIntArray Remove(int n, int k);
    CIntArray Replace(int val, int key);
    CIntArray AddHead(int n);
    CIntArray AddTail(int n);
    CIntArray Insert(int val, int k);
    int Max();
    int min();
    CIntArray Ascending();
    CIntArray Descending();
    bool IsSymmetry();
    CIntArray MoveForward();
    CIntArray MoveForward(int n);
    CIntArray MoveBehind();
    CIntArray MoveBehind(int n);
    CIntArray Invert();
    int Appearance(int n);
};

#endif // ARRAYW2_H