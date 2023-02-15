/**
 * @file ShortestCommonSupersequence.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Shortest Common Supersequence
MediumAccuracy: 55.62%Submissions: 65K+Points: 4
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.
Example 2

Input:
X = efgh, Y = jghi
Output: 6
Explanation: Shortest Common Supersequence
would be ejfghi which is of length 6 and
has both the strings as its subsequences.
Your Task:
Complete shortestCommonSupersequence() function that takes X, Y, m, and n as arguments and returns the length of the required string.

Expected Time Complexity: O(Length(X) * Length(Y)).
Expected Auxiliary Space: O(Length(X) * Length(Y)).

Constraints:
1<= |X|, |Y| <= 100
 *
 * @version 0.1
 * @date 2023-02-15 03:36 PM
 *
 * @copyright Copyright (c) 2023
 *
 */

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find length of shortest common supersequence of two strings.

    /*
    Method 1: This problem is closely related to longest common subsequence problem.
    Below are steps.

    Find Longest Common Subsequence (lcs) of two given strings. For example, lcs of “geek” and “eke” is “ek”.
    Insert non-lcs characters (in their original order in strings) to the lcs found above, and return the result. So “ek” becomes “geeke” which is shortest common supersequence.
    Let us consider another example, str1 = “AGGTAB” and str2 = “GXTXAYB”. LCS of str1 and str2 is “GTAB”. Once we find LCS, we insert characters of both strings in order and we get “AGXGTXAYB”
    How does this work?

    We need to find a string that has both strings as subsequences and is the shortest such string. If both strings have all characters different, then result is sum of lengths of two given strings. If there are common characters, then we don’t want them multiple times as the task is to minimize length. Therefore, we first find the longest common subsequence, take one occurrence of this subsequence and add extra characters.

    Length of the shortest supersequence
    = (Sum of lengths of given two strings)
    - (Length of LCS of two given strings)
    Below is the implementation of above idea. The below implementation only finds length of the shortest super sequence.

    
    Time Complexity: O(m*n).
    Auxiliary Space: O(m*n)
    
    */
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        // code here
        int dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (Y[i - 1] == X[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return X.length() + Y.length() - dp[n][m];
    }

/**
 * @brief Method 2: A simple analysis yields below simple recursive solution.

Let X[0..m - 1] and Y[0..n - 1] be two 
strings and m and n be respective
lengths.

    if (m == 0) return n;
    if (n == 0) return m;

    // If last characters are same, then 
    // add 1 to result and
    // recur for X[]
    if (X[m - 1] == Y[n - 1])
        return 1 + SCS(X, Y, m - 1, n - 1);

    // Else find shortest of following two
    //  a) Remove last character from X and recur
    //  b) Remove last character from Y and recur
    else 
        return 1 + min( SCS(X, Y, m - 1, n), SCS(X, Y, m, n - 1) );


Below is simple naive recursive solution based on above recursive formula. 

    Time Complexity: O(2min(m, n)). Since there are overlapping subproblems, 
    Auxiliary Space: O(min(m, n)), due to recursive call stack
 * 
 */
// supersequence of X and Y
// int shortestCommonSupersequence(string X, string Y, int m, int n)
// {
//         if (!m)
//             return n;
//         if (!n)
//             return m;
    
//         if (X[m - 1] == Y[n - 1])
//             return 1 + shortestCommonSupersequence(X, Y, m - 1, n - 1);
    
//         return 1
//             + min(shortestCommonSupersequence(X, Y, m - 1, n),
//                     shortestCommonSupersequence(X, Y, m, n - 1));
// }

/*
    Method 3: We can efficiently solve this recursive problem using Dynamic Programming. Below is the Dynamic Programming-based implementation. 

    Time Complexity: O(m*n).
    Auxiliary Space: O(m*n)
*/
    // int shortestCommonSupersequence(string X, string Y, int m, int n)
    // {
    //     //code here
    //     int dp[n+1][m+1];

    //     for (int i=0; i<=n; i++)
    //     {
    //         for (int j=0; j<=m; j++)
    //         {
    //             if (!i)
    //                 dp[i][j] = j;
    //             else if (!j)
    //                 dp[i][j] = i;
    //             else if (Y[i-1] == X[j-1])
    //                 dp[i][j] = 1 + dp[i-1][j-1];
    //             else
    //                 dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
    //         }
    //     }

    //     return dp[n][m];
    // }
};

//{ Driver Code Starts.

int main()
{

    int t;

    // taking total testcases
    cin >> t;
    while (t--)
    {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size()) << endl;
    }
    return 0;
}

// } Driver Code Ends