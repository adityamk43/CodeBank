/**
 * @file DigitalRoot.cpp
 * @author ADITYA BHARDWAJ
 * @brief Digital Root
EasyAccuracy: 53.0%Submissions: 35023Points: 2
You are given a number n. You need to find the digital root of n. DigitalRoot of a number is the recursive sum of its digits until we get a single digit number.

Example 1:

Input:
n = 1
Output:  1
Explanation: Digital root of 1 is 1
Example 2:

Input:
n = 99999
Output: 9
Explanation: Sum of digits of 99999 is 45
which is not a single digit number, hence
sum of digit of 45 is 9 which is a single
digit number.
Your Task:
You don't need to read input or print anything. Your task is to complete the function digitalRoot that takes n as parameter and returns the digital root of n.

Expected Time Complexity: O((Num of Digits)2).
Expected Auxiliary Space: O(Num of Digits).

Constraints:
1 <= n <= 107
 * @version 0.1
 * @date 2022-08-21
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Complete this function
    int sumOfDigits(int n)
    {
        if (n <= 9)
            return n;

        return sumOfDigits(n / 10) + n % 10;
    }

    int digitalRoot(int n)
    {
        // Your code here

        // Another short way Approach!!
        if (n <= 9)
            return n;

        return digitalRoot(n % 10 + n / 10);

        // Professional Way of my approach
        //  if (n <= 9)
        //      return n;

        // else
        //     return digitalRoot(sumOfDigits(n));

        // my approach which can be confusing
        //  if (n<=9)
        //      return n;

        // int res = digitalRoot(n/10) + n%10;

        // if (res>9)
        //     return digitalRoot(res/10) + res%10;
        // else return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T; // taking testcases
    while (T--)
    {
        int n;
        cin >> n; // taking number n

        // calling digitalRoot() function
        Solution obj;
        cout << obj.digitalRoot(n) << endl;
    }
    return 0;
}
// } Driver Code Ends