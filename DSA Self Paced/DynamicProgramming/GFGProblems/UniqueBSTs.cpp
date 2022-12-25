/**
 * @file UniqueBSTs.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Unique BST's
MediumAccuracy: 30.57%Submissions: 63K+Points: 4
Lamp
Land your Dream Job with Mega Job-a-thon. Register Now!

Given an integer. Find how many structurally unique binary search trees are there that stores the values from 1 to that integer (inclusive).

Example 1:

Input:
N = 2
Output: 2
Explanation:for N = 2, there are 2 unique
BSTs
     1               2
      \            /
       2         1
Example 2:

Input:
N = 3
Output: 5
Explanation: for N = 3, there are 5
possible BSTs
  1           3     3       2     1
    \        /     /      /  \     \
     3      2     1      1    3     2
    /      /       \                 \
   2      1         2                 3


Your Task:
You don't need to read input or print anything. Your task is to complete the function numTrees() which takes the integer N as input and returns the total number of Binary Search Trees possible with keys [1.....N] inclusive. Since the answer can be very large, return the answer modulo 1e9 + 7.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N).

Constraints:
1<=N<=1000
 *
 * @version 0.1
 * @date 2022-12-25 11:11 AM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the total number of possible unique BST.
    int numTrees(int n)
    {
        // Your code here
        if (n == 0)
            return 1;

        int mod = 1000000007;

        int dp[n + 1];

        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;

            for (int j = 0; j < i; j++)
            {
                dp[i] = (dp[i] + (1LL * dp[j] * dp[i - j - 1]) % mod) % mod;
            }
        }

        return dp[n];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9 + 7)
int main()
{

    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {

        // taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        // calling function numTrees()
        cout << ob.numTrees(n) << "\n";
    }
}
// } Driver Code Ends