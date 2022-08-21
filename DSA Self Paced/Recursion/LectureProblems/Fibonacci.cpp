/**
 * @file Fibonacci.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 4:13PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

//(n>=0)
int fib(int n)
{
    if (n<=1)
        return n;
    
    return fib(n-1) + fib(n-2);
}

int main()
{
    cout << fib(3) << endl;
    return 0;
}