/**
 * @file StockBuyAndSell.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-03 01:18AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(n^2)
    AUXILIARY SPACE/SPACE COMPLEXITY: O(1)
*/

/*
    RECURSION METHOD
*/

int maxProfit(int *arr, int start, int end)
{
    if (start>=end)
        return 0;
    
    int profit = 0;
    for (int i=start; i<end; i++)
    {
        for (int j=i+1; j<=end; j++)
        {
            if (arr[j] > arr[i])
            {
                int curr_Profit = (arr[j] - arr[i]) + maxProfit(arr, start, i-1) + maxProfit(arr, j+1, end);
                profit = max(profit, curr_Profit);
            }

        }
    }

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

    cout << maxProfit(arr, 0, n-1);

    return 0;
}