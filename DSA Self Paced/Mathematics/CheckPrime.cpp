/**
 * @file CheckPrime.cpp
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

bool CheckPrime(int n)
{
    if (n<=1)
        return false;
    
    if (n==2 || n==3)
        return true;

    if (n%2 == 0 || n%3 == 0)
        return false;

    for (int i=5; i*i<=n; i=i+6)
    {
        if (n%i==0 || n%(i+2) == 0)
            return false;
    }

    return true;
}

int main()
{
    int n;

    cin >> n;

    if (CheckPrime(n))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}