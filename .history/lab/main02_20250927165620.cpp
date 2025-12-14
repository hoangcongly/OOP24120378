#include "arrayw2.h"

int main() {
    srand(time(0));

    cout << "=== Test CIntArray ===\n";

    // Test constructor mặc định + Input/Output
    CIntArray arr1;
    arr1.InputArray();
    cout << "Mang arr1: "; arr1.OutputArray();

    // Test constructor có tham số
    int rawArr[] = {5, 2, 5, 3, 5, 2, 5};
    CIntArray arr2(rawArr, 7);
    cout << "\nMang arr2 (raw init): "; arr2.OutputArray();

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

    // Test Max / Min
    cout << "Max arr2: " << arr2.Max() << endl;
    cout << "Min arr2: " << arr2.Min() << endl;

    // Test Ascending / Descending
    arr2.Ascending();
    cout << "arr2 tang dan: "; arr2.OutputArray();
    arr2.Descending();
    cout << "arr2 giam dan: "; arr2.OutputArray();

    // Test IsSymmetry
    int symArr[] = {1, 2, 3, 2, 1};
    CIntArray arr4(symArr, 5);
    cout << "\narr4: "; arr4.OutputArray();
    cout << "arr4 co doi xung? " << (arr4.IsSymmetry() ? "YES" : "NO") << endl;

    // Test MoveForward / MoveBehind
    cout << "\narr2 truoc MoveForward: "; arr2.OutputArray();
    arr2.MoveForward(2);
    cout << "arr2 sau MoveForward(2): "; arr2.OutputArray();
    arr2.MoveBehind(2);
    cout << "arr2 sau MoveBehind(2): "; arr2.OutputArray();

    // Test Invert
    arr2.Invert();
    cout << "arr2 sau Invert: "; arr2.OutputArray();

    // Test Appearance
    cout << "So lan xuat hien cua 2 trong arr2: " << arr2.Appearance(2) << endl;

    cout << "\n=== Ket thuc test ===\n";
    return 0;
}
