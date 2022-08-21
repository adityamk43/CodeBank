/**
 * @file FactorialFunction.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 4:11PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

//(n>=0)
int fact(int n)
{
    if (n==0)
        return 1;
    
    return n*fact(n-1);

}

int main()
{
    cout << fact(5) << endl;
    return 0;
}