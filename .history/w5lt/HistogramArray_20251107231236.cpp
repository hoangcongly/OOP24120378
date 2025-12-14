#include "HistogramArray.h"

HistogramArray::HistogramArray() : Array()
{
    histSize = 10;
    histogram = new int[histSize];
    for (int i = 0; i < histSize; i++)
    {
        histogram[i] = 0;
    }
}

HistogramArray::HistogramArray(int s, int hsize) : Array(s), histSize(hsize)
{
    histogram = new int[histSize];
    computeHistogram();
}

HistogramArray::~HistogramArray()
{
    delete[] histogram;
    histSize = 0;
}

HistogramArray::HistogramArray(const HistogramArray &other) : Array(other), histSize(other.histSize)
{
    histogram = new int[histSize];
    for (int i = 0; i < histSize; i++)
    {
        histogram[i] = other.histogram[i];
    }
}
