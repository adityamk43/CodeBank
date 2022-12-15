/**
 * @file UniqueSubsets.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Unique Subsets
MediumAccuracy: 39.89%Submissions: 31K+Points: 4
Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.

Note: Each subset should be sorted.

Example 1:

Input: N = 3, arr[] = {2,1,2}
Output:(),(1),(1 2),(1 2 2),(2),(2 2)
Explanation:
All possible subsets = (),(2),(1),(1,2),(2),(2,2),(2,1),(2,1,2)
After Sorting each subset = (),(2),(1),(1,2),(2),(2,2),(1,2),(1,2,2)
Unique Susbsets in Lexicographical order = (),(1),(1,2),(1,2,2),(2),(2,2)
Example 2:

Input: N = 4, arr[] = {1,2,3,3}
Output: (),(1),(1 2),(1 2 3)
(1 2 3 3),(1 3),(1 3 3),(2),(2 3)
(2 3 3),(3),(3 3)
Your Task:
Your task is to complete the function AllSubsets() which takes the array arr[] and N as input parameters and returns list of all possible unique subsets in lexicographical order.

Expected Time Complexity: O(2N).
Expected Auxiliary Space: O(2N * X), X = Length of each subset.

Constraints:
1 ≤ N ≤ 12
1 ≤ arr[i] ≤ 9
 *
 * @version 0.1
 * @date 2022-12-15 02:49 PM
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
    // Function to find all possible unique subsets.

    void uniqueSubsetsRec(vector<int> &arr, int n, int k, vector<vector<int>> &vect, vector<int> &v)
    {
        vect.push_back(v);

        if (k == n)
            return;

        for (int i = k; i < n; i++)
        {
            v.push_back(arr[i]);
            uniqueSubsetsRec(arr, n, i + 1, vect, v);
            v.pop_back();
        }
    }

    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        // code here
        vector<vector<int>> vect;
        vector<int> v;

        sort(arr.begin(), arr.end());

        uniqueSubsetsRec(arr, n, 0, vect, v);

        sort(vect.begin(), vect.end());
        vect.resize(distance(vect.begin(), unique(vect.begin(), vect.end())));

        return vect;
    }
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
        vector<int> A;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int>> result = obj.AllSubsets(A, n);
        // printing the output
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}

// } Driver Code Ends