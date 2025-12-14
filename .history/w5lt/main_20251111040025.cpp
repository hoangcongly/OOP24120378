#include <stdexcept>
#include "HistogramArray.h"

int main()
{
    int arr[6] = {0, 1, 0, 2, 3, 4};
    Array a1(6, arr);
    a1[3] = 4;
    a1.display();
    HistogramArray a2(6, arr, 5);
    a2.computeHistogram();
    a2.displayHistogram();
    a2[3] = 4;
    a2.computeHistogram();
    a2.displayHistogram();

    a2.setValue(1, 4);
    std::cout << "a2 (sau khi setValue): ";
    a2.display();
    a2.displayHistogram();
    return 0;
}