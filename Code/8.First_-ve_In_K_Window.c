// First negative integer in every window of size k

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *arr;
int k;
int res[130];

int *first_negative(int *arr, int size, int k)
{

    int l = 0;
    int j;

    for (int i = 0; i < size - k + 1; i++)  // IMPORTANT
    {
        for (j = i; j < k + i; j++)  // CHECKS for K size subarray at every i th iteration,
        {
            if (arr[j] < 0)
            {
                res[l++] = arr[j];
                break;
            }
        }
        if (j == i + k)
        {
            res[l++] = 0;
        }
    }
    return res;
}

int main()
{

    return 0;
}