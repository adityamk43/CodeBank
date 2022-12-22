/**
 * @file CoinChange.java
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Coin Change - Number of ways
EasyAccuracy: 69.0%Submissions: 9K+Points: 2
Lamp
Land your Dream Job with Mega Job-a-thon. Register Now!  

You have an infinite supply of coins, each having some value. Find out the number of ways to use the coins to sum-up to a certain required value.

Example 1:

Input:
value = 4
numberOfCoins = 3
coins[] = {1,2,3}
Output: 4
Explanation: We need to make the change
for value = 4. The denominations are
{1,2,3} Change for 4 can be made:
1+1+1+1
1+1+2
1+3
2+2
So, as it is evident, we can do this in
4 ways.
Example 2:

Input:
value = 10
numberOfCoins = 4
coins[] = {2,5,3,6}
Output: 5
Your Task:
This is a function problem where you've to complete the funcion numberOfWays (). You are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the given coins. You need to return the number of ways you can make the change for value using the coins of given denominations. Also, keep in mind that you have an infinite supply of coins.
Note:  Try not to editing the part of the code provided to you in the function. Just complete the function as it has been described.

Expected Time Complexity: O(Number of Coins * Value).
Expected Auxiliary Space: O(Value).

Constraints:
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000
 *
 * @version 0.1
 * @date 2022-12-21 11:50 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

// import java.io.*;
import java.util.*;

class CoinChange {
    public static void main(String[] args) {

        // taking input using Scanner class
        Scanner sc = new Scanner(System.in);

        // taking total count of testcases
        int testcases = sc.nextInt();
        while (testcases-- > 0) {
            // taking value
            int value = sc.nextInt();

            // taking number of coins
            int numberOfCoins = sc.nextInt();
            int coins[] = new int[numberOfCoins];

            // inserting coins to the array
            for (int i = 0; i < numberOfCoins; i++) {
                int x = sc.nextInt();
                coins[i] = x;
            }

            // creating an object of class Geeks
            Solution obj = new Solution();

            // calling method numberOfWays() of class Geeks
            System.out.println(obj.numberOfWays(coins, numberOfCoins, value));
        }

        sc.close();
    }
}

// } Driver Code Ends
// User function Template for Java

class Solution {
    // Function to find out the number of ways to use the coins to
    // sum up to a certain required value.
    public long numberOfWays(int coins[], int numberOfCoins, int value) {
        long dp[] = new long[value + 1];

        dp[0] = 1;

        for (int i = 1; i <= value; i++)
            dp[i] = 0;

        for (int j = 0; j < numberOfCoins; j++) {
            for (int i = 1; i <= value; i++) {
                if (coins[j] <= i)
                    dp[i] += dp[i - coins[j]];
            }
        }

        return dp[value];

    }
}

// { Driver Code Starts.

// } Driver Code Ends