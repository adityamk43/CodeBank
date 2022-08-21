/**
 * @file 1ToNTailRecursion.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 4:06PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

//Initially pass k=1
void print1ToN(int n, int k)
{
    if (n==0)
        return;
        
    cout << k << " ";
    print1ToN(n-1, k+1);
}

int main()
{
    print1ToN(5, 1);
    return 0;
}