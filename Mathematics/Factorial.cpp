/**
 * @file Factorial.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-20 12:00:00 AM ++ just after 2022-06-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

long long Factorial(int n)
{
    long long res = 1;

    if (n<0)
        return -1;

    for (int i=2; i<=n; i++)
        res *= i;

    return res;
}

int main()
{
    int n;

    cin >> n;

    cout << Factorial(n);

    return 0;
}