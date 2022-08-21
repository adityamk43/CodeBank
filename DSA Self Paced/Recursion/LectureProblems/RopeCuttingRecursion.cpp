/**
 * @file RopeCuttingRecursion.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 8:13PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

int ropeCutting(int n, int a, int b, int c)
{
    if (n==0)
        return 0;
    
    if (n<0)
        return -1;
    
    int res = max(ropeCutting(n-a, a, b, c),
                max(ropeCutting(n-b, a, b, c),
                ropeCutting(n-c, a, b, c)));  

    if (res==-1)
        return -1;
    
    return res+1;

}

int main()
{
    //Test Cases
    // cout << ropeCutting(5, 2, 5, 1) << endl;
    cout << ropeCutting(23, 12, 9, 11) << endl;
    // cout << ropeCutting(5, 4, 2, 6) << endl;

    //Interesting corner case
    // cout << ropeCutting(9, 2, 2, 2) << endl;

    //To check worst Case time complexity
    // cout << ropeCutting(5, 1, 1, 1) << endl;
    return 0;
}