/**
 * @file MultiplicationBy3.5.cpp
 * @author Aditya Bhardwaj
 * @brief (Quiz Question Bit Magic - DSA Self-Paced). Shortcut and optimised method to multiple any integer number by 3.5
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
    int x;
    cin >> x;

    cout << (x<<1) + x + (x>>1);

    return 0;
}