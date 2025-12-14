#include "b01.h"

int main()
{
    Address addr("123 Main St", "Hanoi", "Vietnam");
    ExchangeStudent ex("Nguyen Van A", "12345", 3.6, addr, "France", 6);

    ex.display();

    cout << "\n--- Update duration ---\n";
    ex.updateDuration(12);
    ex.display();

    return 0;
}