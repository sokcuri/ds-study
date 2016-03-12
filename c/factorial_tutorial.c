#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial_recursive(int n)
{
    if (n == 0) return 1;
    return n*factorial_recursive(n-1);
}

int factorial_repeat(int n)
{
    int i, sum = 1;
    for (i = n; i > 0; i--)
        sum *= i;
    return sum;
}

int main(void)
{
    clock_t start, finish;
    start = clock();
    for (int j=0; j<100000; j++)
        for (int i=0; i<14; i++)
            factorial_recursive(i);
    finish = clock();
    printf("recursive factorial : %f\n", (double)(finish-start)/CLOCKS_PER_SEC);

    start = clock();
    for (int j=0; j<100000; j++)
        for (int i=0; i<14; i++)
            factorial_repeat(i);
    finish = clock();
    printf("repeat factorial : %f\n", (double)(finish-start)/CLOCKS_PER_SEC);

    printf("factorial_recursive(10) : %d\n", factorial_recursive(10));
    printf("factorial_repeat(10) : %d\n", factorial_repeat(10));

}
