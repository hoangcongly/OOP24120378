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
    HistogramArray();
    HistogramArray(int s, int hsize);

    ~HistogramArray();
    HistogramArray(const HistogramArray &other);
    HistogramArray &operator=(const HistogramArray &other);

    virtual void setValue(int index, int value) override;

    void displayHistogram() const;
};

#endif