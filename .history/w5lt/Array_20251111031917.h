#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array
{
protected:
    int *data;
    int size;

public:
    Array();
    Array(int s);
    Array(int s, int *data);

    virtual ~Array();
    Array(const Array &other);
    Array &operator=(const Array &other);
    int getSize() const;
    int getValue(int index) const;
    int &operator[](int index);
    virtual void setValue(int index, int value);

    virtual void display() const;
};

#endif