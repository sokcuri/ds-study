#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double power_repeat(double x, int n)
{
    int i;
    double r = 1.0;
    for (i = 0; i < n; i++)
        r *= x;
    return r;
}

double power_recursive(int x, int n)
{
    if (n == 0) return 1;
    if (n % 2 == 1) // odd
        return x * power_recursive(x * x, n / 2);
    else return power_recursive(x * x, n / 2);
}

// divide and conquer
double power_repeat_divide(int x, int n)
{
    double r = 1.0;
    while(n > 0)
    {
        if (n % 2 == 1)
        {
            r *= x;
            n--;
        }
        n /= 2;
        x *= x;
    }
    return r;
}

int main()
{
    printf("power_repeat(2,3) : %f\n", power_repeat(2, 3));
    printf("power_recursive(2,3) : %f\n", power_recursive(2, 3));
    printf("power_repeat_divide(2,3) : %f\n", power_repeat_divide(2, 3));

    clock_t start, end;
    start = clock();
    for (int i=0; i < 10000000; i++)
        power_repeat(2, 3);
    end = clock();
    printf("power_repeat : %fms\n", (double)(end-start)/CLOCKS_PER_SEC);

    start = clock();
    for (int i=0; i < 10000000; i++)
        power_recursive(2, 3);
    end = clock();
    printf("power_recursive : %fms\n", (double)(end-start)/CLOCKS_PER_SEC);

    start = clock();
    for (int i=0; i < 10000000; i++)
        power_recursive(2, 3);
    end = clock();
    printf("power_repeat_divide : %fms\n", (double)(end-start)/CLOCKS_PER_SEC);
}
