#include "arrayw2.h"

int main() {
    srand(time(0));

    cout << "=== Test CIntArray ===\n";

    // Test constructor mặc định + Input/Output
    CIntArray arr1;
    arr1.InputArray();
    cout << "Mang arr1: "; arr1.OutputArray();

    // Test copy constructor từ rawArr
    CIntArray rawArr;
    rawArr.InputArray();
    CIntArray arr2(rawArr);   // copy constructor
    cout << "\nMang arr2 (copy from rawArr): "; arr2.OutputArray();

    // Test copy constructor
    CIntArray arr3(arr2);
    cout << "Mang arr3 (copy arr2): "; arr3.OutputArray();

    // Test Remove trùng
    arr2.Remove();
    cout << "arr2 sau Remove duplicate: "; arr2.OutputArray();

    // Test Remove theo index
    arr3.Remove(2);
    cout << "arr3 sau Remove(2): "; arr3.OutputArray();

    // Test Remove(k, n)
    arr3.Remove(1, 2);
    cout << "arr3 sau Remove(1,2): "; arr3.OutputArray();

    // Test Replace
    arr2.Replace(5, 9);
    cout << "arr2 sau Replace 5->9: "; arr2.OutputArray();

    // Test AddHead + AddTail
    arr2.AddHead(100).AddTail(200);
    cout << "arr2 sau AddHead(100), AddTail(200): "; arr2.OutputArray();

    // Test Insert
    arr2.Insert(999, 2);
    cout << "arr2 sau Insert(999,2): "; arr2.OutputArray();

    // Test Max / Mi
