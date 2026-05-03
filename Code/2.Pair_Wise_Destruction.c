// Given an array of n strings arr[]. The task is to determine the number of words remaining after pairwise destruction. If two consecutive words in the array are identical, they cancel each other out. This process continues until no more eliminations are possible. USE STACK.

// Examples:

// Input: arr[] = ["gfg", "for", "geeks", "geeks", "for"]
// Output: 1
// Explanation: After the first iteration, we'll have: [gfg, for, for]. Then after the second iteration, we'll have: [gfg]. No more eliminations are possible. Hence, the result is 1

#include <stdio.h>
#include <string.h>

char *stack[130];
int top = -1;

int pairwise_destruction(char **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        stack[++top] = arr[i];
    }

    char *res[130];
    int j = 0;

    while (top != -1)
    {
        if (j > 0 && strcmp(res[j - 1], stack[top]) == 0) // This means strings are equal
        {
            j--;   
            top--;
        }
        else
        {
            res[j++] = stack[top--];
        }
    }

    return j;
}

int main()
{
    return 0;
}