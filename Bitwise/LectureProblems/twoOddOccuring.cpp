/**
 * @file TwoOddOccuring.cpp
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

void twoOddOccuring(int arr[], int n)
{
    int num1 = 0, num2 = 0;
    int XOR  = 0;

    for (int i=0; i<n; i++)
        XOR = XOR ^ arr[i];

    int sn = XOR & ~(XOR-1);

    for (int i=0; i<n; i++)
    {
        if ((arr[i] & sn) != 0)
            num1 = num1 ^ arr[i];
        else
            num2 = num2 ^ arr[i];
    }
    

    cout << num1 << " " << num2 << endl;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 3, 5, 5, 5, 5, 7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    twoOddOccuring(arr, n);
    return 0;
}