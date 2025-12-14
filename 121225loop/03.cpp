#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    double result = 2;
    for (int i = 1; i <= n; i++)
    {
        result = 2 + sqrt(result);
    }
    printf("%.2lf", result - 2);
}
