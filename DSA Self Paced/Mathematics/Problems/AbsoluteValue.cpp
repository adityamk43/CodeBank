/*
You are given an interger I, find the absolute value of the interger I.

Example 1:

Input:
I = -32
Output: 32
Explanation: 
The absolute value of -32 is 32.


Example 2:

Input:
I = 45
Output: 45
Explanation: 
The absolute value of 45 is 45 itself.


Your Task:
You don't need to read input or print anything. Your task is to complete the function absolute() which takes an integer I as input parameter and return the absolute value of I.


Expected Time Complexity: O(1)
Expected Auxiliary Space : O(1)

Constraints:
-106 <= I <= 106
*/


//@AUTHOR: ADITYA BHARDWAJ
//@CREATED: 16 JUNE 2022

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
        int absolute(int I) {
        // Your code goes here
        
            if (I<0)
                return (-I);
            
            return (I);
        
    }

};

// { Driver Code Starts.

int main() {
    int T;    // number of testcases
    cin >> T; // input number of testcases
    while (T--) {
        int I;
        cin >> I;
        Solution ob;
        cout << ob.absolute(I) << endl; // print the output
    }
    return 0;
}  // } Driver Code Ends