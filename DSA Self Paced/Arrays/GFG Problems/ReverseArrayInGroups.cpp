/**
 * @file ReverseArrayInGroups.cpp
 * @author ADITYA BHARDWAJ
 * @version 0.1
 * @date 2022-09-02 01:02AM
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * @brief Reverse array in groups
BasicAccuracy: 51.16%Submissions: 100k+Points: 1
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

Note: If at any instance, there are no more subarrays of size greater than or equal to K, then reverse the last subarray (irrespective of its size).

Example 1:

Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.


Example 2:

Input:
N = 4, K = 3
arr[] = {5,6,8,9}
Output: 8 6 5 9


Your Task:
You don't need to read input or print anything. The task is to complete the function reverseInGroups() which takes the array, N and K as input parameters and modifies the array in-place.



Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)



Constraints:
1 ≤ N, K ≤ 107
1 ≤ A[i] ≤ 1018
 *
 */

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to reverse every sub-array group of size k.

    //MY APPROACH
    // void reverseArray(vector<long long> &arr, int start, int end, int k)
    // {
    //     if (start >= arr.size())
    //     {
    //         // cout << "Start: " << start << "    ";
    //         return;
    //     }

    //     int low = start;
    //     int high;

    //     if (end >= arr.size())
    //         high = arr.size() - 1;
    //     else
    //         high = end;

    //     // cout << "Low: " << low << "  " << "High: " << high << "   ";
    //     while (low < high)
    //     {
    //         swap(arr[low], arr[high]);
    //         low++;
    //         high--;
    //     }

    //     // cout << "Start: " << start + k << "  " << "End: " << end + k << "  ";

    //     reverseArray(arr, start + k, end + k, k);
    // }

    // void reverseInGroups(vector<long long> &arr, int n, int k)
    // {
    //     // code here
    //     reverseArray(arr, 0, k - 1, k);
    // }

/*
    Example: 
        I/P: 
            size = 33, k = 13
            arr[] = 36 93 64 48 96 55 70 0 82 30 16 22 38 53 19 50 91 43 70 88 10 57 14 94 13 36 59 32 54 58 18 82 67
        O/P:
            arr[] = 38 22 16 30 82 0 70 55 96 48 64 93 36 36 13 94 14 57 10 88 70 43 91 50 19 53 67 82 18 58 54 32 59
*/

    //SIMPLER APPROACH
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {
        // code here
        for (int i=0; i<n; i+=k)
        {
            int start = i;

            int end = min(i+k-1, n-1);

            while (start<end)
                swap(arr[start++], arr[end--]);
        }
    }

    //Shortest and clear cpp code for vector
    // void reverseInGroups(vector<long long> &arr, int n, int k)
    // {
    //     for(int l=0; l<n; l+=k)
    //         reverse(arr.begin()+l,arr.begin()+min(n,k+l));
    // }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr;
        int k;
        cin >> k;

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for (long long i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends