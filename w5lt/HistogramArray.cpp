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
HistogramArray::HistogramArray(int s, int *data, int hsize)
    : Array(s, data), histSize(hsize)
{
    histogram = new int[histSize];
    for (int i = 0; i < histSize; i++)
    {
        histogram[i] = 0;
    }
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

HistogramArray &HistogramArray::operator=(const HistogramArray &other)
{
    if (this == &other)
    {
        return *this;
    }
    Array::operator=(other);
    delete[] histogram;
    histSize = other.histSize;
    histogram = new int[histSize];
    for (int i = 0; i < histSize; i++)
    {
        histogram[i] = other.histogram[i];
    }
    return *this;
}

void HistogramArray::computeHistogram()
{
    // 1 1 5 4 2 5 1 3 5
    // 0 3 1 1 1 2
    for (int i = 0; i < histSize; i++)
    {
        histogram[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (data[i] >= 0 && data[i] < histSize)
        {
            histogram[data[i]]++;
        }
    }
}

void HistogramArray::setValue(int index, int value)
{
    Array::setValue(index, value);
    computeHistogram();
}

void HistogramArray::displayHistogram() const
{
    for (int i = 0; i < histSize; i++)
    {
        std::cout << i << "->" << histogram[i];
        if (i < histSize - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}