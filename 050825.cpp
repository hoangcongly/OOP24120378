#include <stdio.h>
int main()
{
    printf("Nhap gia tri X: ");
    int x, n;
    scanf("%d", &x);
    printf("Nhap gia tri N: ");
    scanf("%d", &n);
    double sum=0.00;
    int tu=1.00;
    int mau=0.00;
    
    for(int i=1; i<=n; i++)
    {
         tu*=x;
         mau+=i;
        sum+=(double)tu/mau;
    }
    printf("%lf", sum);
    return sum;
}