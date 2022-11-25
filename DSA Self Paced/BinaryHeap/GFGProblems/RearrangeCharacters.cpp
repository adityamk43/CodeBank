/**
 * @file RearrangeCharacters.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Rearrange characters
MediumAccuracy: 47.9%Submissions: 7218Points: 4
Lamp
Save 25% with Black Friday Offers. Explore Now!

Given a string S such that it may contain repeated lowercase alphabets. Rearrange the characters in the string such that no two adjacent characters are same.


Example 1:

Input:
S = geeksforgeeks
Output: 1
Explanation: egeskerskegof can be one way of
rearranging the letters.

Example 2:

Input:
S = bbbabaaacd
Output: 1
Explanation: abababdcab can be one way of
rearranging the letters.

Your Task:
You do not need to read input or print anything. Complete the function rearrangeString() which takes string S as input parameter and returns the string after rearrangement.
If the characters are successfully rearranged then the generated output will be 1 else 0.


Expected Time Complexity : O(|S| log |S|)
Expected Auxilliary Space : O(1)


Constraints:
1 <= |S| <= 105
String has only lowercase English alphabets.
 *
 * @version 0.1
 * @date 2022-11-25 06:39 PM
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
    // Function to rearrange the characters in a string such that
    // no two adjacent characters are same.
    string rearrangeString(string str)
    {
        // Your code here
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < str.length(); i++)
        {
            m[str[i]]++;
        }

        // 	for (auto &x: m)
        // 	    cout << x.first << ":" << x.second << endl;

        for (auto &x : m)
        {
            if (x.second > 0)
                pq.push({x.second, x.first});
        }

        string ans = "";
        pair<int, char> prev = make_pair(-1, '#');

        while (!pq.empty())
        {
            pair<int, char> p = pq.top();
            pq.pop();

            ans += p.second;

            if (prev.first > 0)
                pq.push(prev);

            (p.first)--;
            prev = p;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int checker(string str, string pat)
{
    int freq[26];
    for (int i = 0; i < 26; i++)
        freq[i] = 0;
    if (str.length() != pat.length())
        return 0;
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i] - 97]--;
        if (pat[i] < 97 || pat[i] > 122)
            return 0;
        freq[pat[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
        if (freq[i] != 0)
            return 0;
    for (int i = 0; i < pat.length() - 1; i++)
        if (pat[i] == pat[i + 1])
            return 0;
    return 1;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string str, ret;
        cin >> str;
        Solution ob;
        ret = ob.rearrangeString(str);
        cout << checker(str, ret) << endl;
    }
    return 0;
}
// } Driver Code Ends