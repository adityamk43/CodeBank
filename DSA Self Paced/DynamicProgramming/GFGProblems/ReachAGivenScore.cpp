/**
 * @file ReachAGivenScore.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Reach a given score
EasyAccuracy: 66.42%Submissions: 19K+Points: 2
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find the number of distinct combinations to reach the given score.

Example 1:

Input:
n = 8
Output: 1
Explanation:when n = 8,{3,5} and {5,3}
are the two possible permutations but
these represent the same combination.
Hence output is 1.
Example 2:

Input:
n = 20
Output: 4
Explanation:When n = 20, {10,10},
{5,5,5,5},{10,5,5} and {3,3,3,3,3,5}
are different possible permutations.
Hence output will be 4.
Your Task:
Complete count() function which takes N as an argument and returns the number of ways/combinations to reach the given score.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ n ≤ 1000
 *
 * @version 0.1
 * @date 2023-02-14 12:54 PM
 *
 * @copyright Copyright (c) 2023
 *
 */

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll count(ll n);

int main()
{
    // taking total testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking the score
        ll n;
        cin >> n;

        // calling function count()
        cout << count(n) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// User function tempate for C++

// Function to find the number of distinct combinations to reach the given score.
ll count(ll n)
{
    // code here
    vector<ll> dp(n + 1, 0);

    int score[] = {3, 5, 10};
    dp[0] = 1;

    for (int i = 0; i < 3; i++)
    {
        for (ll j = 3; j <= n; j++)
        {
            if (j - (ll)score[i] >= 0)
                dp[j] += dp[j - (ll)score[i]];
        }
    }

    return dp[n];
}