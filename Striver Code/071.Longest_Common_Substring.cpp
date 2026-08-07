// Given two strings str1 and str2, find the length of their longest common substring.

// A substring is a contiguous sequence of characters within a string.

// Input: str1 = "abcde", str2 = "abfce"

// Output: 2

// Explanation: The longest common substring is "ab", which has a length of 2.

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int SpaceOptimised(string str1, string str2)
    {
        int index1 = str1.length();
        int index2 = str2.length();

        vector<int> prev(index2 + 1, -1);

        // Base case: if either string is empty,
        // longest common substring length is 0.
        for (int j = 0; j <= index2; j++)
        {
            prev[j] = 0;
        }

        // Start from 0 because there may be no common substring at all.
        int ans = 0;

        for (int i = 1; i <= index1; i++)
        {
            vector<int> curr(index2 + 1, -1);

            // First column is always 0 (empty second string).
            curr[0] = 0;

            for (int j = 1; j <= index2; j++)
            {
                // If characters match, extend the previous diagonal substring.
                if (str1[i - 1] == str2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];

                    // Store the maximum substring length seen so far.
                    ans = max(ans, curr[j]);
                }
                else
                {
                    // IMPORTANT:
                    // Unlike LCS, a substring must be contiguous.
                    // So on mismatch, the current substring breaks completely.
                    curr[j] = 0;
                }
            }

            // Move current row to previous for the next iteration.
            prev = curr;
        }

        // IMPORTANT:
        // The answer is NOT necessarily in the last cell.
        // It can end anywhere in the DP table, so return the maximum found.
        return ans;
    }

    int longestCommonSubstr(string str1, string str2)
    {
        int index1 = str1.length();
        int index2 = str2.length();

        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, -1));

        // Base case: empty string with anything gives substring length 0.
        for (int i = 0; i <= index1; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= index2; j++)
        {
            dp[0][j] = 0;
        }

        // Start from 0 because there may be no common substring.
        int ans = 0;

        for (int i = 1; i <= index1; i++)
        {
            for (int j = 1; j <= index2; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    // Extend the previous matching substring.
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                    // Keep track of the best answer seen anywhere.
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    // IMPORTANT:
                    // A substring cannot skip characters.
                    // Mismatch means the current substring ends here.
                    dp[i][j] = 0;
                }
            }
        }

        // IMPORTANT:
        // For Longest Common Substring, the answer can be present
        // at any cell, not necessarily dp[index1][index2].
        return ans;
    }
};