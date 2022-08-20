/**
 * @file bitDifference.cpp
 * @author ADITYA BHARDWAJ
 * @brief You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

Example 1:

Input: A = 10, B = 20
Output: 4
Explanation:
A  = 01010
B  = 10100
As we can see, the bits of A that need
to be flipped are 01010. If we flip
these bits, we get 10100, which is B.
Example 2:

Input: A = 20, B = 25
Output: 3
Explanation:
A  = 10100
B  = 11001
As we can see, the bits of A that need
to be flipped are 10100. If we flip
these bits, we get 11001, which is B.

Your Task: The task is to complete the function countBitsFlip() that takes A and B as parameters and returns the count of the number of bits to be flipped to convert A to B.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ A, B ≤ 106
 * @version 0.1
 * @date 2022-08-20
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

class Solution
{
public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countSetBits(int n)
    {
        int res = 0;

        while (n > 0)
        {
            n = n & (n - 1);
            res++;
        }

        return res;
    }

    int countBitsFlip(int a, int b)
    {

        // Your logic here
        int aXORb = a ^ b;

        int count = countSetBits(aXORb);

        return count;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;   // input the testcases
    while (t--) // while testcases exist
    {
        int a, b;
        cin >> a >> b; // input a and b

        Solution ob;
        cout << ob.countBitsFlip(a, b) << endl;
    }
    return 0;
}
// } Driver Code Ends