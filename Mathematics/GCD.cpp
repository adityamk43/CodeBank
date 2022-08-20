/**
 * @file GCD.cpp
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

int GCD(int a, int b)
{
    if (a==0)
        return b;

    return GCD(b%a, a);
} 

int main()
{   
    int a, b;

    cin >> a >> b;

    int gcd = GCD(a, b);

    cout << endl << gcd;

    return 0;
}