/**
 * @file countTotalSetBits.cpp
 * @author ADITYA BHARDWAJ
 * @brief You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Example 1:

Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.
Example 2:

Input: N = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive),
the total number of set bits is 35.

Your Task: The task is to complete the function countSetBits() that takes n as a parameter and returns the count of all bits.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 108
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
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int maxPow2(int n)
    {
        int count = 0;
        while ((1 << count) <= n)
        {
            count++;
        }

        return (count - 1);
    }

    int countSetBits(int n)
    {
        // Your logic here

        // RECURSION LOGIC
        if (n == 0)
            return 0;

        int x = maxPow2(n);
        int total = x * (1 << (x - 1)) + (n - (1 << x)) + 1 + countSetBits(n - (1 << x));

        // ITERATIVE LOGIC
        // int total=0;
        //  while (n>0)
        //  {
        //      int x = maxPow2(n);
        //      total += x * (1<<x)/2 + (n - (1<<x)) + 1;

        //     n = n & ~(1<<x);

        //     while (n > 0 && x>0)
        //     {
        //         if (n & (1<<x))
        //             break;

        //         x--;
        //     }
        // }

        return total;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}

// } Driver Code Ends