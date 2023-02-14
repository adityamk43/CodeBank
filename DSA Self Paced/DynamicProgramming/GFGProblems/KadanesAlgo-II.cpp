/**
 * @file KadanesAlgo-II.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Kadane's Algorithm - II
EasyAccuracy: 31.67%Submissions: 9K+Points: 2
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

You are given an array arr of size sizeOfArr. You need to find the maximum sum in the array provided that you cannot sum neighboring elements or adjacent elements.

Example 1:

Input:
sizeOfArr = 4
arr[] = {4,5,6,7,8}
Output: 18
Explanation:The given elements are 4 5 6 7 8
For 4, the maximum sum will be 4 as no
element other than 4 from index 0 to 0
For 5, the maximum sum will be 5 as we cannot
add 4 and 5(neighboring elements).
For 6, the maximum sum will be 10 as we can
add 6 and 4.
For 7, the maximum sum will be 12 as we can
add 7 and 5.
For 8, the maximum sum will be 18 as we can
add 4 and 6 and 8.
Example 2:

Input:
sizeOfArr = 5
arr[] = {-9,-8,8,3,-4}
Output: 8
Your Task:
This is a function problem. You only need to complete the function maximumSum() that takes array and sizeOfArray and returns the maximum sum of the array provided that you cannot sum neighboring elements.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ sizeOfArr ≤ 104
-103 ≤ arri ≤ 103
 *
 * @version 0.1
 * @date 2023-02-14 11:56 AM
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
    // Function to return the maximum sum without adding adjacent elements.
    long long maximumSum(int arr[], int sizeOfArray)
    {
        // Your code here
        long long dp[sizeOfArray];

        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < sizeOfArray; i++)
            dp[i] = max(dp[i - 1], max(arr[i] + dp[i - 2], (long long)arr[i]));

        return dp[sizeOfArray - 1];
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

        // inserting elements in the array
        for (int i = 0; i < sizeOfArray; i++)
            cin >> arr[i];
        Solution ob;
        // calling function maximumSum()
        cout << ob.maximumSum(arr, sizeOfArray) << endl;
    }
    return 0;
}
// } Driver Code Ends