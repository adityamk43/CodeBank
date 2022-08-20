/**
 * @file LCM.cpp
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

int LCM(int a, int b)
{
    return (a*b)/GCD(a, b);
}

int main()
{   
    int a, b;

    cin >> a >> b;

    int lcm = LCM(a, b);

    cout << endl << lcm;

    return 0;
}