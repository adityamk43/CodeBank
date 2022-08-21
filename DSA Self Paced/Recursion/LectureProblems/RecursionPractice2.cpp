/**
 * @file RecursionPractice2.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 4:00PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

int logFun(int n)
{
    if (n==1)
        return 0;
    
    else
        return 1 + logFun(n/2);
}

void Dec2Bin(int n)
{
    if (n==0)
        return;
    
    Dec2Bin(n/2);

    cout << (n%2);
}

int main()
{
    cout << logFun(16);
    // cout << logFun(31);
    // cout << logFun(19);
    // cout << logFun(32);
    cout << endl << "logFun() Ends Here";
    cout << endl << endl;
    // Dec2Bin(13);
    Dec2Bin(7);
    cout << endl << "Dec2Bin() Ends Here";
    cout << endl << endl;
    return 0;
}