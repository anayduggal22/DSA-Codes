// Circular Tour

// In the circular tour problem, we are given petrol at each petrol pump and the distance required to reach the next pump. We try to find a starting pump from which the truck can complete the full circle without running out of petrol. While traversing the pumps, we keep calculating the current petrol balance (petrol - distance). If the balance becomes negative, it means the tour cannot start from the current starting pump, so we move the starting point to the next pump and store the shortage in deficit. At the end, if the total petrol (balance + deficit) is non-negative, the stored starting pump is the correct answer; otherwise, completing the tour is impossible.

#include <stdio.h>

// Function to find the starting petrol pump
int circularTour(int petrol[], int distance[], int n)
{

    int start = 0;   // starting petrol pump
    int balance = 0; // current petrol balance
    int deficit = 0; // petrol shortage

    for (int i = 0; i < n; i++)
    {

        // petrol gained - petrol required to reach next pump
        balance += petrol[i] - distance[i];

        // If petrol becomes negative, tour cannot start from current start
        if (balance < 0)
        {
            start = i + 1;      // move starting point to next pump
            deficit += balance; // store shortage
            balance = 0;        // reset balance
        }
    }

    // If total petrol is enough, return starting pump
    if (balance + deficit >= 0)
    {
        return start;
    }

    return -1; // tour not possible
}

int main()
{

    int petrol[] = {4, 6, 7, 4};
    int distance[] = {6, 5, 3, 5};

    int n = 4;

    int start = circularTour(petrol, distance, n);

    printf("Start at pump: %d", start);

    return 0;
}