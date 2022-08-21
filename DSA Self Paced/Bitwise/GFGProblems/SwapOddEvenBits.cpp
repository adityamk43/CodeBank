/**
 * @file SwapOddEvenBits.cpp
 * @author ADITYA BHARDWAJ
 * @brief Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit is swapped with an adjacent bit on the right side(even position bits are highlighted in the binary representation of 23), and every odd position bit is swapped with an adjacent on the left side.

Example 1:

Input: N = 23
Output: 43
Explanation:
Binary representation of the given number
is 00010111 after swapping
00101011 = 43 in decimal.
Example 2:

Input: N = 2
Output: 1
Explanation:
Binary representation of the given number
is 10 after swapping 01 = 1 in decimal.

Your Task: Your task is to complete the function swapBits() which takes an integer and returns an integer with all the odd and even bits swapped.


Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 109
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

class Solution
{
public:
    // Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        // Your code here
        int res = 0;
        int i = 0, j = 1;
        while (n > 0)
        {
            int bit1 = n & 1;
            n = n >> 1;
            int bit2 = n & 1;
            n = n >> 1;

            res = res | (bit1 << j) | (bit2 << i);

            i += 2;
            j += 2;
        }

        return res;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        unsigned int n;
        cin >> n; // input n

        Solution ob;
        // calling swapBits() method
        cout << ob.swapBits(n) << endl;
    }
    return 0;
}
// } Driver Code Ends