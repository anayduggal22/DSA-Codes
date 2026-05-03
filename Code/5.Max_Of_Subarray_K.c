// Maximum of all subarrays of size K

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *arr;
int k;
int res[130];

int *max_subarrays(int *arr, int size, int k)
{
    int max;
    int gmax = INT_MIN;
    int l = 0;

    for (int i = 0; i < size - k + 1; i++) // IMPORTANT
    {
        for (int j = i; j < k + i; j++) // CHECKS for K size subarray at every i th iteration,
        {
            max = arr[j];
            if (max > gmax)
            {
                gmax = max;
            }
        }
        res[l++] = gmax;
        gmax = INT_MIN;

    }
    return res;
}

int main()
{

    return 0;
}