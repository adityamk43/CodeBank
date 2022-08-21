/**
 * @file SumOfDigits.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 8:11PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

int getSumOfDigits(int n)
{
    // if (n==0)
    //     return 0;
    
    //reduces time complexity and aux space from d+1 to d where d is the number of digits in input number n
    if (n<=9)
        return n;
    
    return getSumOfDigits(n/10) + n%10;
}

int main()
{
    cout << getSumOfDigits(873);

    return 0;
}