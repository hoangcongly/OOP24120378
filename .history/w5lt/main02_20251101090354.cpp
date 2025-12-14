#include "b02.h"

int main()
{
    Client c("Alice", "C001");
    SavingAccount s(c, 1001, 1000, 0.05);

    s.applyInterest();
    s.display();

    return 0;
}
