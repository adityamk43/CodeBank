/**
 * @file Divisors.cpp
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

void Divisors(int n)
{
    int i;

    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
            cout << i << endl;
    }

    for (; i >= 1; i--)
    {
        if (n % i == 0)
            cout << n / i << endl;
    }
}

int main()
{
    int n;

    cin >> n;

    Divisors(n);

    return 0;
}