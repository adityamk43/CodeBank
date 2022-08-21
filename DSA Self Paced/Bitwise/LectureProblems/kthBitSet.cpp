/**
 * @file kthBitSet.cpp
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

bool kthBitSet(int x , int k){

    //Using Left Shift
    // if ( (x & (1<<(k-1))) != 0)
    //     return true;
    
    // return false;

    //Using Right Shift
    if ((x>>(k-1) & 1) == 1)
        return true;
    
    return false;
}

int main()
{
    int x = 5, k;
    cin >> k;

    cout << kthBitSet(x , k) << endl;

    return 0;
}