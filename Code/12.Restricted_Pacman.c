// Restricted Pacman

#include <stdio.h>

int restricted_pacman(int m, int n)
{
    // To check if numbers are coprime or not
    int ans;
    if (gcd(m, n) != 1)
    {
        return -1;
    }

    else if (gcd(m, n) == 1)
    {
        ans = (m - 1) * (n - 1);
        ans /= 2;
    }

    return ans;
}

int main()
{

    return 0;
}