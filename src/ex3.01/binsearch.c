#include<stdio.h>
#include<time.h>
#define N 1000000000
clock_t start, end;

int V[N];

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid]) 
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch1(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    if (v[low] == x) return low;
    return -1;
}


int
main(void)
{
    
    int x = 5000, pos;
    for (size_t i = 0; i < N; i++)
    {
        V[i] = i + 51;
    }
    printf("Clocks per second: %i\n", CLOCKS_PER_SEC);
    start = clock();
    pos = binsearch2(x, V, N);
    end = clock();
    printf("binsearch2 for n = %i, x = %i, took %lu us, pos = %i\n", N, x, (end-start), pos);

    start = clock();
    pos = binsearch1(x, V, N);
    end = clock();
    printf("binsearch1 for n = %i, x = %i, took %lu us, pos = %i\n", N, x, (end-start), pos);
    return 0;
}