/**
 * @file PrimeFactor.cpp
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

void PrimeFactor(int n)
{
    if (n <= 1)
        return;

    while (n % 2 == 0)
    {
        cout << 2 << endl;
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        cout << 3 << endl;
        n = n / 3;
    }

    for (int i = 5; i * i <= n; i = i + 6)
    {
        while (n % i == 0)
        {
            cout << i << endl;
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            cout << i + 2 << endl;
            n = n / (i + 2);
        }
    }

    if (n>3)
        cout << n;
}

int main()
{
    int n;
    
    cin >> n;

    PrimeFactor(n);

    return 0;
}