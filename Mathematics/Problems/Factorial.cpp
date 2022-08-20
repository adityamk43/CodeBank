/*
Given a positive integer N. The task is to find factorial of N.

Example 1:

Input:
N = 4
Output: 24
Explanation: 4! = 4 * 3 * 2 * 1 = 24
Example 2:

Input:
N = 13
Output: 6227020800
Explanation: 
13! = 13 * 12 * .. * 1 = 6227020800
Your Task:
You don't need to read input or print anything. Your task is to complete the function factorial() that takes N as parameter and returns factorial of N.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
0 <= N <= 18
*/

//@AUTHOR: ADITYA BHARDWAJ
//@CREATED: 16 JUNE 2022

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
long long factorial(int);

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
        // Complete this function
    long long factorial(int N) {
        // Your code here
        
        long long fact = 1;
        
        if (N == 1 || N == 0 )
            return 1;
        
        for (int i = 2; i <= N; i++)
        {
            fact = fact * i;
        }
        
        return fact;
    }

};

// { Driver Code Starts.
int main() {
    int T, N;
    cin >> T; // input number of testcases
    while (T--) {
        cin >> N; // input n
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0;
}
  // } Driver Code Ends