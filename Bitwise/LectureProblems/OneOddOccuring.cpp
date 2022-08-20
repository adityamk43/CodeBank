/**
 * @file OneOddOccuring.cpp
 * @author Aditya Bhardwaj (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int oneOddOccuring(int arr[], int n)
{
    int XOR=0;

    for (int i=0; i< n; i++)
        XOR = XOR ^ arr[i];
    
    return XOR;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 5, 5, 5, 5, 7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << oneOddOccuring(arr, n)<<endl;
    return 0;
}