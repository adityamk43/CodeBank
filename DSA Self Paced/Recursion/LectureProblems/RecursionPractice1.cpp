/**
 * @file RecursionPractice1.cpp
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

void fun1(int n)
{
    if (n == 0)
        return;

    cout << n << endl;
    fun1(n - 1);
    cout << n << endl;
}

void fun2(int n)
{
    if (n == 0)
        return;

    fun2(n - 1);
    cout << n << endl;
    fun2(n - 1);
}

int main()
{
    fun1(3);
    cout << endl << "fun1() Ends Here";
    cout << endl << endl;
    fun2(3);
    cout << endl << "fun2() Ends Here";
    cout << endl << endl;
    return 0;
}