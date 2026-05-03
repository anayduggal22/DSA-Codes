// Priority Queue Using Max Heap

#include <iostream>
#include <vector>

using namespace std;

// Down to UP
void heapify(int *heap, int size)
{
    // Only 1 Node, i.e root
    if (size == 1)
    {
        return;
    }

    // Node position to heapify
    int i = size - 1;

    while (i > 0)
    {
        // At right place in heap
        if (heap[i] < heap[(i - 1) / 2])
        {
            break;
        }
        // Greater than parent, so swap
        else
        {
            int temp = heap[i];
            heap[i] = heap[(i - 1) / 2];
            heap[(i - 1) / 2] = temp;

            // Now go to that index
            i = (i - 1) / 2;
        }
    }
}

// Insert into priority queue
void push(int *heap, int *size, int value)
{
    heap[*size] = value;
    (*size)++;

    // Fix heap
    heapify(heap, *size);
}

// Heapify from UP to Down
int deletion(int *heap, int size)
{
    // Removing Root by giving it value of end leaf, and then heapifying it downwards
    heap[0] = heap[size - 1];
    size--;

    // From top
    int i = 0;

    while (2 * i + 1 < size)
    {
        // Initially, i is largest
        int index = i;

        // If left child larger
        if (heap[2 * i + 1] > heap[index])
        {
            index = 2 * i + 1;
        }

        // If right child larger
        if (heap[2 * i + 2] > heap[index])
        {
            index = 2 * i + 2;
        }

        // Swap with larger child
        if (index != i)
        {
            int temp = heap[i];
            heap[i] = heap[index];
            heap[index] = temp;
            
            // New index of i
            i = index;
        }
        else
        {
            break;
        }
    }

    return size;
}

// Pop max element
int pop(int *heap, int *size)
{
    int max = heap[0];
    *size = deletion(heap, *size);
    return max;
}

// Get max element
int top(int *heap)
{
    return heap[0];
}

int main()
{
    int heap[100];
    int size = 0;

    // Insert elements
    push(heap, &size, 23);
    push(heap, &size, 14);
    push(heap, &size, 22);
    push(heap, &size, 10);
    push(heap, &size, 9);
    push(heap, &size, 6);

    printf("Max element: %d\n", top(heap));

    printf("Priority Queue (max to min): ");
    while (size > 0)
    {
        printf("%d ", pop(heap, &size));
    }

    return 0;
}