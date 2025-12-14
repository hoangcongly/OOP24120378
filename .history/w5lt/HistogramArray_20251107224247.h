#ifndef HISTOGRAMARRAY_H
#define HISTOGRAMARRAY_H

#include <iostream>
#include "Array.h"

class HistogramArray : public Array
{
private:
    int *histogram;
    int histSize;
    void computeHistogram();

public:
};

#endif