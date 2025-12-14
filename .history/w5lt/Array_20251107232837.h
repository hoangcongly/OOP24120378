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

    virtual ~Array();
    Array(const Array &other);
    Array &operator=(const Array &other);
    int getSize() const;
    int getValue(int index) const;
    virtual void setValue(int index, int value);

    virtual void display() const;
};

#endif