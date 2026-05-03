// Given an integer k and a queue of integers, The task is to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.
// Only following standard operations are allowed on the queue.

// enqueue(x): Add an item x to rear of queue
// dequeue(): Remove an item from the front of the queue
// size(): Returns the number of elements in the queue.
// front(): Finds front item.
// Example:

// Input: q = 1 2 3 4 5, k = 3
// Output: 3 2 1 4 5
// Explanation:  After reversing the first 3 elements from the given queue the resultant queue will be 3 2 1 4 5.

// Input: q = 4 3 2 1, k= 4
// Output: 1 2 3 4
// Explanation: After reversing the first 4 elements from the given queue the resultant queue will be 1 2 3 4.

#include <stdio.h>

int queue[130];
int f = -1;
int r = -1;

void enqueue(int data)
{
    if (r < 129)
    {
        queue[++r] = data;
    }
}

void dequeue()
{
    if (f < r)
    {
        f++;
    }
}

int size()
{
    return r - f;
}

int front()
{
    if (f < r)
    {
        int a = queue[f + 1];
        return a;
    }
    return -1;
}

void reverse_k_queue(int k)
{
    int arr[130];
    int j = 0;

    for (int i = f + 1; i <= r; i++)
    {
        arr[j++] = queue[i];
        dequeue();
    }
    
    int size_arr = j;
    f = r = -1;

    j = k - 1; // IMPORTANT
    int i = 0;
    int temp;

    while (i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    for (int i = 0; i < size_arr; i++)
    {
        enqueue(arr[i]);
    }
}

int main()
{

    return 0;
}