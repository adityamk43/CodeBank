/**
 * @file CombinationSum.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Combination Sum
MediumAccuracy: 28.28%Submissions: 66K+Points: 4
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.


Example 1:

Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)
Example 2:

Input:
N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
Output:
(1 1 1 1 1 1)
(1 1 1 1 2)
(1 1 2 2)
(1 5)
(2 2 2)
(6)

Your Task:
Your task is to complete the function combinationSum() which takes the array A and a sum B as inputs and returns a list of list denoting the required combinations in the order specified in the problem description. The printing is done by the driver's code. If no set can be formed with the given set, then  "Empty" (without quotes) is printed.


Expected Time Complexity: O(X2 * 2N), where X is average of summation B/arri for every number in the array.
Expected Auxiliary Space: O(X * 2N)


Constraints:
1 <= N <= 30
1 <= A[i] <= 20
1 <= B <= 100
 *
 * @version 0.1
 * @date 2022-12-14 08:40 PM
 *
 * @copyright Copyright (c) 2022
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
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    void combSumRec(vector<int> &A, int B, int k, vector<vector<int>> &vect, vector<int> &v, int &sum)
    {
        if (sum == B)
        {
            vect.push_back(v);
            return;
        }

        for (int i = k; i < A.size(); i++)
        {

            if (sum + A[i] <= B)
            {
                v.push_back(A[i]);
                sum += A[i];

                combSumRec(A, B, i, vect, v, sum);

                v.pop_back();
                sum -= A[i];
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // Your code here
        vector<vector<int>> vect;
        vector<int> v;
        int sum = 0;

        sort(A.begin(), A.end());

        auto ep = unique(A.begin(), A.end());

        A.resize(distance(A.begin(), ep));

        combSumRec(A, B, 0, vect, v, sum);

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
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
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