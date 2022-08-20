/**
 * @file bitwiseNOT.cpp
 * @author ADITYA BHARDWAJ
 * @brief Bitwise Not (~) Function
 * @version 0.1
 * @date 2022-08-17 10:24PM IST
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{

    //By default compiler uses signed bits for numbers so we may not need to define explicityle for signed numbers but we are doing here for learning purpose on signed and unsigned functioning!!
    signed int x = 1;

    cout << ~x << endl;

    x = 5;

    cout << ~x << endl;

    return 0;
}