/**
 * @file Palindrome.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

bool Palindrome(int n)
{
    int temp = n;
    int rem, rev = 0;

    while(temp>0)
    {
        rem = temp%10;
        rev = rev*10 + rem;

        temp /= 10;
    }

    return n == rev;
}

int main()
{
    int n;

    cin>>n;

    if (Palindrome(n))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}