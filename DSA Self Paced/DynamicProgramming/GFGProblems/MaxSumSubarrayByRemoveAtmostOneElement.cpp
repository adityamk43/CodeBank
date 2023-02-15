/**
 * @file MaxSumSubarrayByRemoveAtmostOneElement.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Max sum subarray by removing at most one element
MediumAccuracy: 32.53%Submissions: 16K+Points: 4
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

You are given array A of size n. You need to find the maximum-sum sub-array with the condition that you are allowed to skip at most one element.

Example 1:

Input:
n = 5
A[] = {1,2,3,-4,5}
Output: 11
Explanation: We can get maximum sum
subarray by skipping -4.
Example 2:

Input:
n = 8
A[] = {-2,-3,4,-1,-2,1,5,-3}
Output: 9
Explanation: We can get maximum sum
subarray by skipping -2 as [4,-1,1,5]
sums to 9, which is the maximum
achievable sum.
Your Task:

Your task is to complete the function maxSumSubarray that take array and size as parameters and returns the maximum sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= n <= 100
-103 <= Ai<= 103
 *
 * @version 0.1
 * @date 2023-02-15 11:19 PM
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
    // Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int A[], int n)
    {
        // Your code here
        int fw[n], bw[n];

        fw[0] = A[0];
        bw[n - 1] = A[n - 1];

        int res = max(fw[0], bw[n - 1]);

        for (int i = 1; i < n; i++)
        {
            fw[i] = max(fw[i - 1] + A[i], A[i]);
            res = max(res, fw[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            bw[i] = max(bw[i + 1] + A[i], A[i]);
            res = max(res, bw[i]);
        }

        for (int i = 1; i < n - 1; i++)
            res = max(res, fw[i - 1] + bw[i + 1]);

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here

    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking total elements
        int n;
        cin >> n;
        int a[n];

        // inserting elements in the array
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // calling method maxSumSubarray()
        Solution obj;
        cout << obj.maxSumSubarray(a, n) << endl;
    }
}

// } Driver Code Ends