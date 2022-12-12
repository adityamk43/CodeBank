/**
 * @file LargestNumberinKSwaps.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Largest number in K swaps
MediumAccuracy: 18.84%Submissions: 69K+Points: 4
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
Example 2:

Input:
K = 3
str = "3435335"
Output:
5543333
Explanation:
Three swaps can make the input
3435335 to 5543333, swapping 3
with 5, 4 with 5 and finally 3 with 4

Your task:
You don't have to read input or print anything. Your task is to complete the function findMaximumNum() which takes the string and an integer as input and returns a string containing the largest number formed by perfoming the swap operation at most k times.


Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ |str| ≤ 30
1 ≤ K ≤ 10
 *
 * @version 0.1
 * @date 2022-12-12 03:33 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the largest number after k swaps.
    void findMaxRec(string str, int k, string &max, int curr)
    {
        if (k == 0)
            return;

        char maxm = str[curr];

        for (int i = curr + 1; i < str.length(); i++)
            if (str[i] > maxm)
                maxm = str[i];

        if (maxm != str[curr])
            --k;

        for (int j = str.length() - 1; j >= 0; j--)
        {
            if (str[j] == maxm)
            {
                swap(str[j], str[curr]);

                if (str.compare(max) > 0)
                    max = str;

                findMaxRec(str, k, max, curr + 1);

                swap(str[j], str[curr]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        // code here.
        string max = str;

        findMaxRec(str, k, max, 0);

        return max;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends