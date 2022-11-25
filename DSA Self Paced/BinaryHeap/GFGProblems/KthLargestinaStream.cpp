/**
 * @file KthLargestinaStream.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Kth largest element in a stream
MediumAccuracy: 42.21%Submissions: 11593Points: 4
Lamp
Save 25% with Black Friday Offers. Explore Now!

Given an input stream of n integers, find the kth largest element each time when an new element is added to the stream.

Example 1:

Input:
k = 4, n = 6
arr[] = {1,2,3,4,5,6}
Output: -1 -1 -1 1 2 3
Explanation: k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1
{1, 2, 3, 4}
For 5, the 4th largest element is 2
{2, 3, 4 ,5}
For 6, the 4th largest element is 3
{3, 4, 5, 6}

Example 2:

Input:
k = 1, n = 2
arr[] = {3,4}
Output: 3 4
Your Task:
You are required to complete the method kthLargest() which takes 3 arguments and prints kth largest element -1.

Constraints:
1 <= n <= 106
1 <= k <= n
1 <= arr[i] <= 105

Expected Time Complexity: O(n*Log(k))
Expected Auxiliary Space: O(k)
 * @version 0.1
 * @date 2022-11-25 06:36 PM
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
    // Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
        // your code here
        priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k);

        for (int i = 0; i < (k - 1); i++)
            cout << -1 << " ";

        for (int i = k; i < n; i++)
        {
            cout << pq.top() << " ";

            if (arr[i] > pq.top())
            {
                pq.push(arr[i]);
                pq.pop();
            }
        }

        if (!pq.empty())
            cout << pq.top() << " ";
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;

        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        ob.kthLargest(arr, n, k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends