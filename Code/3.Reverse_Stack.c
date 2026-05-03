// Given a stack st[], Reverse the stack so that the top element becomes the bottom and the
// bottom element becomes the top, while preserving the order of the remaining elements accordingly.
// Note: The input array represents the stack from bottom to top (last element is the top).
// The output is displayed by printing elements from top to bottom after reversal.

#include <stdio.h>

int stack[130];
int top = -1;
int a;

void reverse_stack()
{
    a = stack[top--]; //POP

    // Base Case
    if (top == -1)
    {
        stack[++top] = a; // PUSH
        return;
    }

    reverse_stack(); // Recurisive case

    stack[++top] = a; // PUSH
}

int main()
{

    return 0;
}