/**
 * @file KMostOccuringElements.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * K Most occurring elements
MediumAccuracy: 58.8%Submissions: 10170Points: 4
Lamp
Save 25% with Black Friday Offers. Explore Now!

Given an array arr[] of N integers in which elements may be repeating several times. Also, a positive number K is given and the task is to find sum of total frequencies of K most occurring elements

Note: The value of K is guaranteed to be less than or equal to the number of distinct elements in arr.

Example 1:

Input:
N = 8
arr[] = {3,1,4,4,5,2,6,1}
K = 2
Output: 4
Explanation: Since, 4 and 1 are 2 most
occurring elements in the array with
their frequencies as 2, 2. So total
frequency is 2 + 2 = 4.
Example 2:

Input:
N = 8
arr[] = {3,3,3,4,1,1,6,1}
K = 2
Output: 6
Explanation: Since, 3 and 1 are most
occurring elements in the array with
frequencies 3, 3 respectively. So,
total frequency is 6.
Your Task:
Complete the function kMostFrequent() whic returns the frequencies of K most occuring elements.

Constraints:
1 <= N <= 106
1 <= K <= N
1 <= arr[i] <= 106

Expected Time Complexity : O(N log N)
Expected Auxilliary Space: O(N)
 * @version 0.1
 * @date 2022-11-25 06:37 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to print the k numbers with most occurrences

class Solution
{
public:
    // Function to return the sum of frequencies of k numbers
    // with most occurrences in an array.
    int kMostFrequent(int arr[], int n, int k)
    {
        // Your code here
        unordered_map<int, int> m;
        int freq = 0;

        // inserting number of occurences of elements in array in a hash map
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }

        // MaxHeap Approach
        // 	priority_queue<int> pq;
        // 	for (auto it=m.begin(); it!=m.end(); it++)
        // 	{
        // 	    pq.push((*it).second);
        // 	}

        // 	for (int i=0; i<k; i++)
        // 	{
        // 	    if (!pq.empty())
        //         {
        //             freq += pq.top();
        //             pq.pop();
        //         }
        // 	}

        // MinHeap Approach using KLargest Elements algorithm!!
        vector<int> v;

        for (auto it = m.begin(); it != m.end(); it++)
            v.push_back((*it).second);

        priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.begin() + k);

        for (int i = k; i < v.size(); i++)
        {
            if (v[i] > pq.top())
            {
                pq.push(v[i]);
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            freq += pq.top();
            pq.pop();
        }

        return freq;
    }
};

//{ Driver Code Starts.
// Driver program to test above
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl;
    }

    return 0;
}

// } Driver Code Ends