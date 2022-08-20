/**
 * @file longestConsecutiveOnes.cpp
 * @author ADITYA BHARDWAJ
 * @brief Given a number N. Find the length of the longest consecutive 1s in its binary representation.

Example 1:

Input: N = 14
Output: 3
Explanation:
Binary representation of 14 is
1110, in which 111 is the longest
consecutive set bits of length is 3.
Example 2:

Input: N = 222
Output: 4
Explanation:
Binary representation of 222 is
11011110, in which 1111 is the
longest consecutive set bits of length 4.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxConsecutiveOnes() which returns the length of the longest consecutive 1s in the binary representation of given N.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
 * @version 0.1
 * @date 2022-08-21
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*  Function to calculate the longest consecutive ones
 *   N: given input to calculate the longest consecutive ones
 */
class Solution
{
public:
    int maxConsecutiveOnes(int N)
    {
        // code here
        int res = 0;
        while (N > 0)
        {
            N = N & (N << 1);
            res++;
        }

        return res;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution obj;
        // calling maxConsecutiveOnes() function
        cout << obj.maxConsecutiveOnes(n) << endl;
    }
    return 0;
}
// } Driver Code Ends