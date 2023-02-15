/**
 * @file SumOfAllSubstringsNumber.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Sum of all substrings of a number
EasyAccuracy: 38.11%Submissions: 18K+Points: 2
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

Given an integer S represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, print it modulo 10^9+7.

Example 1:

Input:
S = 1234
Output: 1670
Explanation: Sum = 1 + 2 + 3 + 4 + 12 +
23 + 34 + 123 + 234 + 1234 = 1670
Example 2:

Input:
S = 421
Output: 491
Explanation: Sum = 4 + 2 + 1 + 42 + 21
Your Task:
You only need to complete the function sumSubstrings that takes S as an argument and returns the answer modulo 1000000007.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= |S| <= 104
 *
 * @version 0.1
 * @date 2023-02-15 11:06 PM
 *
 * @copyright Copyright (c) 2023
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s)
    {
        // your code here
        long long mod = 1000000007;
        int n = s.length();
        long long dp[n];

        dp[0] = (s[0] - '0') % mod;

        long long res = dp[0];

        for (int i = 1; i < n; i++)
        {
            long long digit = (s[i] - '0') % mod;

            dp[i] = ((i + 1) * digit + 10 * dp[i - 1]) % mod;

            res += dp[i];
        }

        return res % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking string
        string s;
        cin >> s;
        Solution ob;
        // calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
    }
    return 0;
}

// } Driver Code Ends