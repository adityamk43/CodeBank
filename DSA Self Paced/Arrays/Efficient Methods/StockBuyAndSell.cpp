/**
 * @file StockBuyAndSell.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 01:45PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;


/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(1)
*/

/*
    VALLEY PEAK APPROACH
*/

#define fl(i, a, b) for (int i=a; i<b; i++)

int maxProfit(int *arr, int n)
{
    int profit=0;

    //running for loop using Macro :) (Always try to learn new techniques ;) )
    fl(i, 1, n)
        if (arr[i] > arr[i-1])
            profit += arr[i] - arr[i-1];
    
    return profit;
}

int main()
{

    int arr[] = {1, 5, 3, 8, 12};
    // int arr[] = {10, 20, 30};
    // int arr[] = {30, 20, 10};
    // int arr[] = {1, 5, 3, 1, 2, 8};
    // int arr[] = {100,180,260,310,40,535,695};

    int n= sizeof(arr)/sizeof(arr[0]);

    cout << maxProfit(arr, n);

    return 0;
}