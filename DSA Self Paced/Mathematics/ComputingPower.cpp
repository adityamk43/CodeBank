/**
 * @file ComputingPower.cpp
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

/*
Recursive Power Solution
Time Complexity: O(logn)
Auxiliary Space: O(logn)
Means extra overhead for function call
*/
int RecursivePower(int x, int n)
{
    if (n == 0)
        return 1;

    int temp = RecursivePower(x, n / 2);

    temp = temp * temp;

    if (n % 2 == 0)
        return temp;
    else
        return temp * x;
}

/*
Iterative Power Solution
Time Complexity: O(logn)
Auxiliary Space: O(1)
Means no overhead for any function call

Uses Binary exponentiation of the power value
*/
long long IterativePower(int x, int n)
{
    long long res = 1;

    while (n > 0)
    {
        if (n % 2 != 0)
            res = res * x;

        x = x * x;
        n = n / 2;
    }

    return res;
}

/*
Iterative Power Solution But through Bitwise Operators
*/

long long IterativeBitwisePower(int x, int n)
{
    long long res = 1;

    while (n > 0)
    {
        if (n & 1)
            res = res * x;

        x = x * x;
        n = n >> 1;
    }

    return res;
}

int main()
{
    int option, x, n;
    cin >> x >> n;
    cout << "1. Recursive Solution (output in int datatype)" << endl;
    cout << "2. Iterative Solution (output in long long datatype)" << endl;
    cout << "3. Iterative Bitwise Operator Solution (output in long long datatype)" << endl;
    cout << "4. Exit" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
    {
        cout << RecursivePower(x, n);
        break;
    }
    case 2:
    {
        cout << IterativePower(x, n);
        break;
    }
    case 3:
    {
        cout << IterativeBitwisePower(x, n);
        break;
    }
    case 4:
    {
        exit(0);
        break;
    }
    default:
    {
        cout << "Invalid Option!!";
        break;
    }
    }

    return 0;
}