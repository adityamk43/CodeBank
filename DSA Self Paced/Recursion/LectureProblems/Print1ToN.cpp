/**
 * @file Print1ToN.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 4:04PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void print1ToN(int n)
{
    if (n==0)
        return;
        
    print1ToN(n-1);
    cout << n << " ";
}

int main()
{
    print1ToN(5);
    return 0;
}