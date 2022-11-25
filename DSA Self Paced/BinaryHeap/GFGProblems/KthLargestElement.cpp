/**
 * @file KthLargestElement.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * Kth largest element
MediumAccuracy: 64.92%Submissions: 13263Points: 4
Lamp
Save 25% with Black Friday Offers. Explore Now!

Given an array arr[] of N positive integers and a number K. The task is to find the kth largest element in the array.

Example 1:

Input:
N = 5, K = 3
arr[] = {3, 5, 4, 2, 9}
Output:
4
Explanation:
Third largest element
in the array is 4.
Example 2:

Input:
N = 5, K = 5
arr[] = {4, 3, 7, 6, 5}
Output:
3
Explanation:
Fifth largest element
in the array is 3.
Your Task:
You are required to complete the method KthLargest() which takes 3 arguments and returns the Kth Largest element.

Constraints:
1 <= N <= 106
1 <= arr[i] <= 106
1 <= K <= N

Expected Time Complexity : O(NlogK)
Expected Auxilliary Space : O(K)
 * @version 0.1
 * @date 2022-11-25 06:34 PM
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
    // Function to return kth largest element from an array.
    int KthLargest(int arr[], int n, int k)
    {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k);

        for (int i = k; i < n; i++)
        {
            if (arr[i] > pq.top())
            {
                pq.push(arr[i]);
                pq.pop();
            }
        }

        return pq.top();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;

        cout << ob.KthLargest(arr, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends