#include <stdio.h>

int main()
{
    double n, x;
    scanf("%lf %lf", &x, &n);
    double result = 0.00;
    double tu = 1.00;
    for (int i = 2; i <= n; i++)
    {
        double mau = 1.00;
        tu *= x * x;
        for (int j = 1; j <= 2 * i; j++)
        {
            mau *= j;
        }
        result += (double)tu / mau;
    }
    printf("%lf", result + 1);
}