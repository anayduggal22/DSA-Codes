// Interleave the First Half of the Queue with Second Half

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

void interleave()
{
    int j = size() / 2;
    int a1[130];
    int a2[130];

    for (int i = 0; i < j; i++)
    {
        a1[i] = front();
        dequeue();
    }

    for (int i = 0; i < j; i++)
    {
        a2[i] = front();
        dequeue();
    }

    f = r = -1;

    int i = 0, k = 0;

    while (i < j && k < j)
    {
        enqueue(a1[i++]);
        enqueue(a2[k++]);
    }
}

int main()
{

    return 0;
}