/**
 * @file totalSetBits.cpp
 * @author Aditya Bhardwaj
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

//Using Brian Kerningham's Method
int totalSetBits(int n)
{
    int res=0;
    
    while (n>0)
    {
        n=(n & (n-1));
        res++;
    }
    
    return res;
}

//Lookup Method
int table[256];

void initializer()
{

    table[0] = 0;

    for (int i=1; i<256; i++)
        table[i] = (i&1) + table[i/2];
}

int totalSetBit(int n)
{
    int res = table[n & 0xff];
    n = n>>8;
    res += table[n & 0xff];
    n = n>>8;
    res += table[n & 0xff];
    n = n>>8;
    res += table[n & 0xff];

    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << totalSetBits(n) << endl;
    initializer();
    cout << totalSetBit(n) << endl; 

    return 0;
}