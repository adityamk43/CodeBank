/**
 * @file JosephusProblem.cpp
 * @author ADITYA BHARDWAJ
 * @brief Josephus problem
EasyAccuracy: 52.47%Submissions: 75916Points: 2
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.

The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.

Example 1:

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so
skipping 1 person i.e 1st person 2nd
person will be killed. Thus the safe
position is 3.


Example 2:

Input:
n = 5 k = 3
Output: 4
Explanation: There are 5 persons so
skipping 2 person i.e 3rd person will
be killed. Thus the safe position is 4.


Your Task:
You don't need to read input or print anything. You are required to complete the function josephus () that takes two parameters n and k and returns an integer denoting safe position.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= k, n <= 20
 * @version 0.1
 * @date 2022-08-23 11:00PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    int myJosephus(int n, int k)
    {
        if (n == 1)
            return 0;

        return (myJosephus(n - 1, k) + k) % n;
    }

    int josephus(int n, int k)
    {
        // Your code here
        return myJosephus(n, k) + 1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n, k;
        cin >> n >> k; // taking input n and k

        // calling josephus() function
        Solution ob;
        cout << ob.josephus(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends