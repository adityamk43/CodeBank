/**
 * @file SumOfNaturalNumbers.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 8:09PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

int getNaturalNumberSum(int n)
{
    if (n==0)
        return 0;
    
    return n + getNaturalNumberSum(n-1);
}

int main()
{
    cout << getNaturalNumberSum(5);
    return 0;
}