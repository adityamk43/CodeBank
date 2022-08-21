/**
 * @file PrintNTo1.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 4:02PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void printNTo1(int n)
{
    if (n==0)
        return;

    cout << n << " ";
    printNTo1(n-1);
}

int main()
{
    printNTo1(5);
    return 0;
}