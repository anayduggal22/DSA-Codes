// First non-repeating character in a Stream

#include <stdio.h>
#include <stdlib.h>

int visited[26]; // Hashmap

void first_non_repeating(char *arr, int size)
{
    // INPUT  -> a a b c
    // OUTPUT -> a # b b
    for (int i = 0; i < size; i++)
    {
        visited[arr[i] - 'a']++; // Its i not j

        int found = 0;

        for (int j = 0; j <= i; j++)
        {
            if (visited[arr[j] - 'a'] == 1) // This means first time visited, so non-repeating    
            {                               // char in this substring.
                printf("%c", arr[j]);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("#");
        }
    }
}

int main()
{
    for (int i = 0; i < 26; i++)
    {
        visited[i] = 0;
    }

    return 0;
}