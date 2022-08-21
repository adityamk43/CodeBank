/**
 * @file SieveOfEratosThenes.cpp
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

void Sieve(int n)
{
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << endl;

            for (int j = i * i; j <= n; j = j+i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    int n;

    cin >> n;

    Sieve(n);

    return 0;
}