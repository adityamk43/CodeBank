/**
 * @file TrailingFactorialZeroes.cpp
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

int TrailingFactorialZeroes(int n)
{
    int sum = 0;

    for (int i=5; i<=n; i=i*5)
    {
        sum += n/i;
    }

    return sum;
}

int main()
{
    int n;

    cin >> n;

    cout << TrailingFactorialZeroes(n);
    
    return 0;
}