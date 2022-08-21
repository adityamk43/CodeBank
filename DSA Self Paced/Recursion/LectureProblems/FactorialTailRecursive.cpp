/**
 * @file FactorialTailRecursive.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * @version 0.1
 * @date 2022-08-21 4:09PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

// Initially pass k=1
int fact(int n, int k)
{
    if (n == 0)
        return k;

    return fact(n - 1, n * k);
}

int main()
{
    cout << fact(3, 1) << endl;
    return 0;
}