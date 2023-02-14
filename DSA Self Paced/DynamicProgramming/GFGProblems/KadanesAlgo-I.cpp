/**
 * @file KadanesAlgo-I.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Kadane's Algorithm - I
EasyAccuracy: 44.39%Submissions: 7K+Points: 2
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

Kadane's algorithm comes into picture when we want to find the maximum possible sum in an array when summing the contiguous elements of the array.

You are given an array. Find the maximum possible sum of contiguous elements of the array ending at each position in the array. Also, return the overall maximum that we can achieve.



Example 1:

Input:
N = 6
arr[] = {5,-2,-3,32,-5,65}
Output: 5 3 0 32 27 92
        92
Explanation: Maximum sum at each index is
5, 3, 0, 32, 27, 92. And, maximum sum for
contiguous array is 92.

Example 2:

Input:
N = 5
arr[] = {-9,-8,8,3,-4}
Output: -9 -8 8 11 7
         11

Your Task:
This is a function problem. You don't need to take any input. Just complete the function maximumSum() that takes the integer array and its size as inputs and prints the maximum contiguous subarray sum ending at each position in the array. Also, return the overall maximum.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= sizeOfArray <= 106
-103 <= Ai <= 103
 *
 * @version 0.1
 * @date 2023-02-14 11:55 AM
 *
 * @copyright Copyright (c) 2023
 *
 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to print the maximum contiguous subarray sum ending at each
    // position in the array and return the overall maximum.
    long long maximumSum(int arr[], int sizeOfArray)
    {
        // code here
        long long dp[sizeOfArray];

        dp[0] = arr[0];
        cout << arr[0] << " ";

        for (int i = 1; i < sizeOfArray; i++)
        {
            if (arr[i] < arr[i] + dp[i - 1])
                dp[i] = arr[i] + dp[i - 1];
            else
                dp[i] = arr[i];

            cout << dp[i] << " ";
        }
        cout << endl;

        long long maxVal = dp[0];

        for (int i = 1; i < sizeOfArray; i++)
            maxVal = max(maxVal, dp[i]);

        return maxVal;
    }
};

//{ Driver Code Starts.
int main()
{

    // taking total testcases
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        // taking size of array
        int sizeOfArray;
        cin >> sizeOfArray;

        int arr[sizeOfArray];

        // inserting elements to the array
        for (int i = 0; i < sizeOfArray; i++)
            cin >> arr[i];
        Solution ob;
        // calling function maximumSum()
        cout << ob.maximumSum(arr, sizeOfArray) << endl;
    }
    return 0;
}
// } Driver Code Ends