/**
 * @file powerSet.cpp
 * @author ADITYA BHARDWAJ
 * @brief Power Set Using Recursion
EasyAccuracy: 49.26%Submissions: 23981Points: 2
You are given a string. You need to print the lexicographically sorted power-set of the string.
Note: The string s contains lowercase letter of alphabet.

Example 1:

Input:
s = a
Output: a
Explanation: empty string and a 
are only sets.
Example 2:

Input:
s = abc
Output: a ab abc ac b bc c
Explanation: empty string, 
a, ab, abc, ac, b, bc, c 
are the sets.
Your Task:
You don't need to read input or print anything. You only need to complete the function powerSet that takes string s as parameter and returns a list of subsets. The lexicographic-sorting and printing is done automatically by the driver code.

Expected Time Complexity: O(2|s|).
Expected Auxiliary Space: O(|s|). 

Constraints:
1 <= |s| <= 10
 * @version 0.1
 * @date 2022-08-23 11:25PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
// Initial Template for C++

// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

void myPowerSet(string &s, vector<string> &currVector, string curr = "", int i = 0)
{
    if (i == s.length())
    {
        currVector.push_back(curr);
        return;
    }

    myPowerSet(s, currVector, curr, i + 1);
    myPowerSet(s, currVector, curr + s[i], i + 1);
}

// Function to return the lexicographically sorted power-set of the string.
vector<string> powerSet(string s)
{
    // Your code here
    vector<string> currVector;
    myPowerSet(s, currVector);

    return currVector;
}

//{ Driver Code Starts.

// Driver code
int main()
{
    int T;
    cin >> T; // testcases
    while (T--)
    {
        string s;
        cin >> s; // input string

        // calling powerSet() function
        vector<string> ans = powerSet(s);

        // sorting the result of the powerSet() function
        sort(ans.begin(), ans.end());

        // printing the result
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends