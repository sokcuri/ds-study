#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    clock_t start, finish;
    double duration;
    start = clock();

    for (int i=0; i < 1000000000; i++);

    finish = clock();

    duration = (double)(finish-start) / CLOCKS_PER_SEC;
    printf("elasped time : %f seconds\n", duration);
}
