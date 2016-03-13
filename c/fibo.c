#include <stdio.h>

int fibo(int n)
{
    if (!n) return 0;
    else if (n == 1) return 1;
    else return (fibo(n-1) + fibo(n-2));
}

int _fibo(int n)
{
    int i, j, k=1, l=0;
    if (!n) return 0;
    else if (n == 1) return 1;
    for (i=2; i <= n; i++)
    {
        j = k;
        k += l;
        l = j;
    }
    return k;
}

int main()
{
    int i;
    for (i=0; i < 10; i++)
        printf("%d ", fibo(i));

    for (i=0; i < 100; i++)
        printf("%d ", _fibo(i));
}
