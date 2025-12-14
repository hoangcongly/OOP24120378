#include <stdio.h>

int main()
{
    int n, x;
    scanf("%d %d", &x, &n);
    double result = 0.00;
    int tu = 1.00;
    for (int i = 2; i <= n; i += 2)
    {
        int mau = 1.00;
        tu *= x * x;
        for (int j = 1; j <= i; j++)
        {
            mau *= j;
        }
        result += (double)tu / mau;
    }
    printf("%lf", result);
}