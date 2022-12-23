/**
 * @file NthCatalanNumber.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Nth catalan number
EasyAccuracy: 31.06%Submissions: 63K+Points: 2
Lamp
Land your Dream Job with Mega Job-a-thon. Register Now!

Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
Note: Positions start from 0 as shown above.

Example 1:

Input:
N = 5
Output: 42
Example 2:

Input:
N = 4
Output: 14
Your Task:
Complete findCatalan() function that takes n as an argument and returns the Nth Catalan number. The output is printed by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 100
 *
 * @version 0.1
 * @date 2022-12-23 10:58 AM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
// Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int; // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find the nth catalan number.
    cpp_int factorial(int n)
    {
        if (n == 0)
            return 1;

        cpp_int fact = 1;

        for (int i = 1; i <= n; i++)
            fact = fact * i;

        return fact;
    }

    cpp_int findCatalan(int n)
    {
        // code here
        cpp_int a = factorial(2 * n);
        cpp_int b = factorial(n);

        return a / (b * b * (n + 1));
    }
};

//{ Driver Code Starts.

int main()
{
    // taking count of testcases
    int t;
    cin >> t;
    while (t--)
    {

        // taking nth number
        int n;
        cin >> n;
        Solution obj;
        // calling function findCatalan function
        cout << obj.findCatalan(n) << "\n";
    }
    return 0;
}
// } Driver Code Ends