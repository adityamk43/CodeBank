/**
 * @file KthSmallestElement.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Kth smallest element
MediumAccuracy: 38.97%Submissions: 100k+Points: 4
Lamp
Save 25% with Black Friday Offers. Explore Now!

Given an array arr[] of N positive integers and a number K. The task is to find the kth smallest element in the array.



Example 1:

Input:
N = 5, K = 3
arr[] = {3,5,4,2,9}

Output:
4

Explanation:
Third smallest element in the array is 4.
Example 2:

Input:
N = 5, k = 5
arr[] = {4,3,7,6,5}

Output:
7

Explanation:
Fifth smallest element in the array is 7.

Your Task:
You  don't need to read inputs or print anything. Complete the method kthSmallest() which takes array arr[], size of the array n and value k as input parameters and returns kth smallest element.

Constraints:
1 <= N <= 106
1 <= arr[i] <= 106
1 <= K <= N
Array do not contains duplicates.

Expected Time Complexity: O(NlogK)
Expected Auxilliary Space: O(K)
 * @version 0.1
 * @date 2022-11-25 06:35 PM
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
    // Function to find the kth smallest element in the array.
    int kthSmallest(int arr[], int n, int k)
    {
        // Your code here
        priority_queue<int, vector<int>> pq(arr, arr + k);

        for (int i = k; i < n; i++)
        {
            if (arr[i] < pq.top())
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

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.kthSmallest(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends