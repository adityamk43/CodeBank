/**
 * @file powerOf2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

bool powOf2(int n)
{
    return ((n!=0) &&  ((n&(n-1))==0) );  
}

int main()
{
    int n;
    cin >> n;

    cout << powOf2(n) << endl;

    return 0;
}