/**
 * @file NumberSparseOrNot.cpp
 * @author ADITYA BHARDWAJ
 * @brief Given a number N. The task is to check whether it is sparse or not. A number is said to be a sparse number if no two or more consecutive bits are set in the binary representation.

Example 1:

Input: N = 2
Output: 1
Explanation: Binary Representation of 2 is 10,
which is not having consecutive set bits.
So, it is sparse number.
Example 2:

Input: N = 3
Output: 0
Explanation: Binary Representation of 3 is 11,
which is having consecutive set bits in it.
So, it is not a sparse number.

Your Task: The task is to complete the function checkSparse() that takes n as a parameter and returns 1 if the number is sparse else returns 0.


Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
// Initial Template for C++

// C++ program to check if n is sparse or not
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to check if the number is sparse or not.
    // MY WAY OF SOLVING THIS QUESTION
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

    bool isSparse(int n)
    {
        // Your code

        int count = maxConsecutiveOnes(n);

        if (count > 1)
            return false;

        return true;
    }

    // EASY AND SHORT METHOD
    //  bool isSparse(int n)
    //  {
    //      // Your code
    //      if ( (n & (n>>1)) == 0)
    //          return true;

    //     return false;
    // }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t, n;

    // testcases
    cin >> t;
    while (t--)
    {
        // initializing n
        cin >> n;

        // printing 1 if isSparse() returns true
        // else 0
        Solution ob;
        if (ob.isSparse(n))
        {
            cout << "1" << endl;
        }
        else
            cout << "0" << endl;
    }
    return 0;
}

// } Driver Code Ends