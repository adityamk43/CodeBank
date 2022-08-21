/**
 * @file StringPalindromRecursion.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 8:03PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &str, int start, int end)
{
    if (start>=end)
        return true;
    
    return (str[start] == str[end]) && isPalindrome(str, start+1, end-1);
}

int main()
{
    //odd length input = abba
    //even length input = cbabc
    string str;
    cin >> str;

    if (isPalindrome(str, 0, str.length()-1))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}