/**
 * @file bitwise.cpp
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

int main()
{
    int x = 3, y=2;
    unsigned int z = 3;

    cout << (x & y) << endl;
    cout << (x | y) << endl;
    cout << (x ^ y) << endl;
    cout << (x << y) << endl;
    cout << (x >> y) << endl;
    cout << (~x) << endl;
    cout << (~z) << endl;


    return 0;
}