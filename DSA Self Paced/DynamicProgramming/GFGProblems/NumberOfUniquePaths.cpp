/**
 * @file NumberOfUniquePaths.cpp
 * @author ADITYA BHARDWAJ 10:45 PM
 * @brief
 *
 * Number of Unique Paths
EasyAccuracy: 67.63%Submissions: 39K+Points: 2
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

Example 1:

Input:
A = 2, B = 2
Output: 2
Explanation: There are only two unique
paths to reach the end of the matrix of
size two from the starting cell of the
matrix.
Example 2:

Input:
A = 3, B = 4
Output: 10
Explanation: There are only 10 unique
paths to reach the end of the matrix of
size two from the starting cell of the
matrix.
Your Task:
Complete NumberOfPath() function which takes 2 arguments(A and B) and returns the number of unique paths from top-left to the bottom-right cell.

Expected Time Complexity: O(A*B).
Expected Auxiliary Space: O(A*B).

Constraints:
1 ≤ A ≤ 15
1 ≤ B ≤ 15
 *
 * @version 0.1
 * @date 2023-02-15
 *
 * @copyright Copyright (c) 2023
 *
 */

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Recursive Function
    // Time Complexity: O(2N)
    // Auxiliary Space: O(N + M)
    //  int NumberOfPath(int a, int b)
    //  {
    //      if (a==1 || b==1)
    //          return 1;

    //     return NumberOfPath(a, b-1) + NumberOfPath(a-1, b);
    // }

    // //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        // code here
        int dp[a + 1][b + 1];

        for (int i = 1; i <= a; i++)
            dp[i][1] = 1;

        for (int i = 1; i <= b; i++)
            dp[1][i] = 1;

        for (int i = 2; i <= a; i++)
            for (int j = 2; j <= b; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[a][b];
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking dimensions of the matrix
        int a, b;
        cin >> a >> b;
        Solution ob;
        // calling NumberOfPath() function
        cout << ob.NumberOfPath(a, b) << endl;
    }
}

// } Driver Code Ends