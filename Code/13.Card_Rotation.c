// Card Rotation

// The idea is to simulate the card rotation using positions instead of actual cards. First, we store the positions of the deck (0 to n-1) in a queue. Then we place the cards 1 to n one by one. For each card i, we rotate the queue i times by moving the front position to the back, which mimics moving cards to the bottom of the deck. After the rotations, we remove the front position from the queue and place the current card number i at that position in the result array. Repeating this for all cards fills the result array in such a way that when the described card-rotation process is applied, the cards will come out in order 1, 2, 3, …, n.

#include <stdio.h>

void main()
{
    int n = 4;

    int q[100];
    int front = -1, rear = n - 1; // IMPORTANT

    int result[100];

    // storing positions in queue
    for (int i = 0; i < n; i++)
    {
        q[i] = i;
    }

    for (int card = 1; card <= n; card++)
    {
        // Rotate 'card' positions
        for (int i = 0; i < card; i++)
        {
            front++;
            rear++;
            q[rear] = q[front];
        }
        
        // Place card in the removed position
        front++;
        int pos = q[front];

        result[pos] = card;
    }

    // Printing final deck
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
}