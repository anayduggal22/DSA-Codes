// Given two strings str1 and str2, find the length of their longest common subsequence.

// A subsequence is a sequence that appears in the same relative order but not necessarily contiguous and a common subsequence of two strings is a subsequence that is common to both strings.

// Input: str1 = "bdefg", str2 = "bfg"

// Output: 3

// Explanation: The longest common subsequence is "bfg", which has a length of 3.

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    string PrintLongestCommonSubsequence(string text1, string text2) {

        // Lengths of both strings
        int index1 = text1.length();
        int index2 = text2.length();

        // DP table
        // dp[i][j] = Length of LCS between first i characters of text1
        //            and first j characters of text2
        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, 0));

        // Filling the DP table
        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {

                // Characters match
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                // Characters don't match
                // Take whichever side gives a longer LCS
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Length of the LCS
        int len = dp[index1][index2];

        // Create a string of required size
        string ans(len, '$');

        // Start from the last cell of DP table
        int i = index1;
        int j = index2;

        // Start filling answer from the back
        int k = len - 1;

        // Backtracking to find the actual LCS
        while (i > 0 && j > 0) {

            // Current characters are part of the LCS
            if (text1[i - 1] == text2[j - 1]) {

                ans[k] = text1[i - 1];

                i--;
                j--;
                k--;
            }

            // Move towards the direction from where
            // the larger LCS length came
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }

            else {
                j--;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    cout << obj.PrintLongestCommonSubsequence("bdefg", "bfg");

    return 0;
}