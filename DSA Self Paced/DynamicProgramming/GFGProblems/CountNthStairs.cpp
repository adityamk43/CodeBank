/**
 * @file CountNthStairs.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * 
 * Count ways to reach the n'th stair
MediumAccuracy: 21.9%Submissions: 144K+Points: 4
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).

Example 1:

Input:
n = 4
Output: 5
Explanation:
You can reach 4th stair in 5 ways. 
Way 1: Climb 2 stairs at a time. 
Way 2: Climb 1 stair at a time.
Way 3: Climb 2 stairs, then 1 stair
and then 1 stair.
Way 4: Climb 1 stair, then 2 stairs
then 1 stair.
Way 5: Climb 1 stair, then 1 stair and
then 2 stairs.
Example 2:

Input:
n = 10
Output: 89 
Explanation: 
There are 89 ways to reach the 10th stair.
Your Task:
Complete the function countWays() which takes the top stair number m as input parameters and returns the answer % 10^9+7.

Expected Time Complexity : O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 104
 * 
 * @version 0.1
 * @date 2023-02-14 11:28 AM
 *
 * @copyright Copyright (c) 2023
 *
 */
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    //Recursive overlappings soln to build DP solution
    // int countWays(int n)
    // {
    //     // your code here
    //     if (n < 0)
    //         return 0;

    //     if (n == 0)
    //         return 1;

    //     return countWays(n - 1) + countWays(n - 2);
    // }
    int countWays(int n)
    {
        // your code here
        int mod=1000000000+7;
        
        int dp[n+1];
    
        dp[0] = 1;
    
        for (int i=1; i<=n; i++)
        {
            if (i-1 >= 0)
                dp[i] = dp[i-1]%mod; 
            if (i-2 >= 0)
                dp[i] += dp[i-2]%mod;
        }
    
        return dp[n]%mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends