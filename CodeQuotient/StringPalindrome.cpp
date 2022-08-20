/*
    EFFICIENT SOLUTION
    The idea is to compare the equidistant characters from start and end in the given string. If all the characters match, then the given string is a palindrome, otherwise it is not.

 Algorithm:

Let n be the length of the given string.
Initialize two variables l and r as 0 and n-1. Use them as indices of the equidistant characters from start and end respectively.
Do the following while (l < r)
If str[l] is not the same as str[r], then return false
Else, Increment l and decrement r, i.e. do l++ and r--
After the comparisons if no mismatch found that means the given string is a palindrome, so return true;


Time Complexity: O(n) ; here n is the length of the given string

Space Complexity: O(1)
*/
/*
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str)
{
    int n = str.length();
    int l = 0, r = n -1;

    // Compare the equidistant characters from start and end
    while (l < r)
    {
        if (str[l] != str[r])
            return false;
        l++;
        r--;
    }

    return true;
}

int main()
{
    string str = "abbccbba";

    if (isPalindrome(str))
        cout << str << " is a palindrome\n";
    else
        cout << str << " is not a palindrome\n";

    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

// Return true if the string is palindrome, else return false
bool isPalindrome(string str)
{
    // Write your code here
    string strrev;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        strrev += str[len - 1 - i];
    }

    if (strrev == str)
        return true;
    else
        return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        // isPalindrome(str);

        if (isPalindrome(str))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

        cout << '\n';
    }
    return 0;
}