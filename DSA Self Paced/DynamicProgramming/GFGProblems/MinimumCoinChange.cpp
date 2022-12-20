/**
 * @file MinimumCoinChange.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Coin Change - Minimum number of coins
EasyAccuracy: 39.43%Submissions: 18K+Points: 2
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

You are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the given coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply of the coins.

Example 1:

Input:
value = 5
numberOfCoins = 3
coins[] = {3,6,3}
Output: Not Possible
Explanation:We need to make the change for
value = 5 The denominations are {3,6,3}
It is certain that we cannot make 5 using
any of these coins.
Example 2:

Input:
value = 10
numberOfCoins = 4
coins[] = {2 5 3 6}
Output: 2
Explanation:We need to make the change for
value = 10 The denominations are {2,5,3,6}
We can use two 5 coins to make 10. So
minimum coins are 2.
Your Task:
You only need to complete the function minimumNumberOfCoins() that take array of coins, size of array, and value as parameters. You need to return the minimum number of coins required. If it is not possible to make the exact value out of the given coin denominations, return -1 ("Not Possible" will be printed by the driver's code in this case).

Expected Time Complexity: O(number of coins * value).
Expected Auxiliary Space: O(value)

Constraints:
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000
 *
 * @version 0.1
 * @date 2022-12-20 02:15 AM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Complete this function

class Solution
{
public:
    // Function to find the minimum number of coins to make the change
    // for value using the coins of given denominations.

    /**
     * @brief this below solution uses 2D array taking extra auxiliary space
     * 
     */
    // long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value)
    // {
    //     // your code here
    //     if (value == 0)
    //         return 0;

    //     long long dp[numberOfCoins + 1][value + 1];

    //     for (int i = 0; i <= numberOfCoins; i++)
    //         dp[i][0] = 0;

    //     for (int j = 1; j <= value; j++)
    //         dp[0][j] = INT_MAX;

    //     for (int i = 1; i <= numberOfCoins; i++)
    //     {
    //         for (int j = 1; j <= value; j++)
    //         {
    //             dp[i][j] = dp[i - 1][j];

    //             if (coins[i - 1] <= j)
    //                 dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
    //         }
    //     }

    //     return dp[numberOfCoins][value] == INT_MAX ? -1 : dp[numberOfCoins][value];
    // }

    /**
     * @brief This is the optimised solution by Sandeep sir taking only value as auxiliary space and same time complexity as above!!
     * 
     * @param coins 
     * @param numberOfCoins 
     * @param value 
     * @return long long 
     */
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {
        // your code here
        if (value == 0)
            return 0;
        
        long long dp[value+1];
        
        dp[0]=0;
        
        for (int i=1; i<=value; i++)
            dp[i] = INT_MAX;
            
        for (int i=1; i<=value; i++)
        {
            for (int j=0; j<numberOfCoins; j++)
            {
                if (coins[j] <= i)
                {
                    long long sub_res = dp[i-coins[j]];
                    
                    if (sub_res!=INT_MAX)
                        dp[i] = min(dp[i], 1+sub_res);
                }
            }
        }
        
        return dp[value] == INT_MAX ? -1 : dp[value];
    }
};

//{ Driver Code Starts.

int main()
{

    // taking total count of testcases
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        // taking value
        int value;
        cin >> value;

        // taking number of coins
        int numberOfCoins;
        cin >> numberOfCoins;
        int coins[numberOfCoins];

        // taking value of each coin
        for (int i = 0; i < numberOfCoins; i++)
            cin >> coins[i];
        Solution obj;
        // calling function minimumNumberOfCoins()
        int answer = obj.minimumNumberOfCoins(coins, numberOfCoins, value);

        // printing "Not Possible" if answer is -1
        // else printing answer
        if (answer == -1)
            cout << "Not Possible" << endl;
        else
            cout << answer << endl;
    }
    return 0;
}
// } Driver Code Ends