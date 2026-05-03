/*
Smallest Subsequence with Perfect Square Product

Approach (Simple Brute Force):

First, we convert each number into prime factor mask.
If a prime factor appears odd number of times, we set a bit.

Then we generate all subsequences using bitmasking.
For each subsequence, we XOR the masks.

If XOR becomes 0, it means all prime powers are even,
so the product is a perfect square.

We store the minimum length of such subsequence.
If no such subsequence exists, print -1.

Time Complexity: O(2^N * N)
*/

#include <bits/stdc++.h>
using namespace std;

// make number square-free
int reduce(int x)
{
    int res = 1;

    for (int i = 2; i * i <= x; i++)
    {
        int cnt = 0;
        while (x % i == 0)
        {
            x /= i;
            cnt++;
        }
        if (cnt % 2)
            res *= i;
    }

    if (x > 1)
        res *= x;
    return res;
}

// check if product is perfect square
bool isPerfectSquare(long long x)
{
    long long s = sqrt(x);
    return s * s == x;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int r = reduce(x);

        if (r == 1)
        {
            cout << 1;
            return 0;
        }

        v.push_back(r);
    }

    sort(v.begin(), v.end());

    // check duplicates → size 2
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
        {
            cout << 2;
            return 0;
        }
    }

    // 🔥 NEW: check triplets (size = 3)
    int ans = INT_MAX;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            for (int k = j + 1; k < v.size(); k++)
            {
                long long prod = 1LL * v[i] * v[j] * v[k];
                if (isPerfectSquare(prod))
                {
                    ans = 3;
                }
            }
        }
    }

    if (ans != INT_MAX)
        cout << ans;
    else
        cout << -1;
}