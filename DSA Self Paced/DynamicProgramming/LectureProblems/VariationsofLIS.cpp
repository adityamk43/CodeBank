/**
 * @file VariationsofLIS.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * In this file, we will see various problems which are variations of LIS problem.
 * 
 * @version 0.1
 * @date 2022-12-19 10:46 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief TIME COMPLEXITY: O(n^2)
 *        AUXILIARY SPACE: ⊝(n)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */

/*
int LIS(int arr[], int n)
{
    int dp[n];
    dp[0] = 1;

    for (int i=1; i<n; i++)
    {
        dp[i]=1;

        for (int j=0; j<i; j++)
        {
            if (arr[j] <= arr[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int max_val = dp[0];

    for (int i=0; i<n; i++)
        max_val = max(max_val, dp[i]);

    return max_val;
}
*/

//WE CAN OPTIMISED THE ABOVE FUNCTION USING BINARY SEARCH!!

/**
 * @brief BINARY SEARCH FOR CEILING (For more understanding refer to binary search video!!)
 * 
 * TIME COMPLEXITY: O(logn)
 * 
 * @param tail 
 * @param l 
 * @param r 
 * @param x 
 * @return int 
 */
int ceilingIdx(int tail[], int l, int r, int x)
{
    while (r>l)
    {
        int m = l + (r-l)/2;

        if (tail[m] >= x)
            r = m;
        else
            l=m+1;
    }

    return r;
}

/**
 * @brief TIME COMPLEXITY: O(nlogn)
 *        AUXILIARY SPACE: ⊝(n)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int LISBinS(int arr[], int n)
{
    int tail[n];

    tail[0] = arr[0];
    int len = 1;

    for (int i=1; i<n; i++)
    {
        if (arr[i] > tail[len-1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c=ceilingIdx(tail, 0, len-1, arr[i]);

            tail[c] = arr[i];
        }
    }

    return len;
}

/**
 * @brief In this problem, we have to find minimum deletions required to make array sorted.
 * 
 * The answer is simple length of the array minus length of the longest increasing subsequence.
 * 
 * TIME COMPLEXITY and AUXILIARY SPACE is same as LIS (nlogn here as we are using optimised version of LIS function!!).
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int minDel(int arr[], int n)
{
    int lis = LISBinS(arr, n);

    return n-lis;
}

/**
 * @brief In this problem we have to find maximum sum of increasing subsequence.
 * 
 * We will not be using original LIS function here, but we will be modifying the O(n^2) t.c. function.
 * 
 * TIME COMPLEXITY: O(n^2)
 * AUXILIARY SPACE: ⊝(n)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int maxSumIS(int arr[], int n)
{
    int msis[n];

    msis[0] = arr[0];

    for (int i=1; i<n; i++)
    {
        msis[i] = arr[i];

        for (int j=0; j<i; j++)
        {
            if (arr[j] < arr[i])
                msis[i] = max(msis[i], arr[i]+msis[j]);
        }
    }

    int maxSum=msis[0];

    for (int i=1; i<n; i++)
        maxSum = max(maxSum, msis[i]);
    

    return maxSum;
}

/**
 * @brief 
 * //REFER GFGPROBLEM FOLDER FOR BITONIC SUBSEQUENCE AS THERE IS SOME ERROR IN O(NLOGN) APPROACH!!
 * Biotonic Subsequence means the subsequence first is in increasing order and then decreasing order.
 * 
 * It is not necessary that Biotonic Subsequence always should either contain increasing order or decreasing order.
 * 
 * Eg:
 * {30, 20, 10}
 * O/P: 3
 * 
 * {10, 20, 30}
 * O/P: 3
 * 
 * TIME COMPLEXITY: O(nlogn), since we are using variation technique of Optimised LIS of Binary Search
 * AUXILIARY SPACE: ⊝(n)
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int maxLenBiotonicSub(int arr[], int n)
{
    int tailLIS[n], tailLDS[n];
    int lis[n], lds[n];
    int lenLIS=1, lenLDS=1;

    tailLIS[0] = arr[0];
    tailLDS[0] = arr[n-1];

    lis[0] = lds[0] = 1;

    //Finding Longest Increasing Subsequences (LIS)
    for (int i=1; i<n; i++)
    {
        if (arr[i] > tailLIS[lenLIS-1])
        {
            tailLIS[lenLIS] = arr[i];
            lis[i] = lenLIS+1;
            lenLIS++;
        }
        else
        {
            int c = ceilingIdx(tailLIS, 0, lenLIS-1, arr[i]);
            tailLIS[c] = arr[i];
            lis[i] = c+1;
        }
    }

    //Finding Longest Decreasing Subsequences (LDS)
    int idx=1;
    for (int i=n-2; i>=0; i--)
    {
        if (arr[i] > tailLDS[lenLDS-1])
        {
            tailLDS[lenLDS] = arr[i];
            lds[idx++] = lenLDS+1;
            lenLDS++;
        }
        else
        {
            int c = ceilingIdx(tailLDS, 0, lenLDS-1, arr[i]);
            tailLDS[c] = arr[i];
            lds[idx++] = c+1;
        }
    }

    //Finding Longest Biotonic Subsequence (LBS)
    int maxVal = lis[0]+lds[0]-1;
    for (int i = 0; i < n; i++)
        maxVal = max(maxVal, lis[i]+lds[i]-1);

    return maxVal;

}


int main()
{
    cout << endl;
    cout << "Choose which variation of LIS you want to see: " << endl;
    cout << "1. Minimum Deletions to make an array sorted " << endl;
    cout << "2. Maximum Sum Increasing Subsequence " << endl;
    //REFER GFGPROBLEM FOLDER FOR BITONIC SUBSEQUENCE AS THERE IS SOME ERROR IN O(NLOGN) APPROACH!!
    cout << "3. Maximum Biotonic Subsequence " << endl;

    int option;
    cin >> option;

    cout << endl << "OUTPUT: ";
    switch(option)
    {
        case 1:
        {
            //EXAMPLE 1
            int arr[] = {5, 10, 3, 6, 7, 8};
            //EXAMPLE 2
            // int arr[] = {30, 20, 10};
            //EXAMPLE 3
            // int arr[] = {10, 20, 30};

            int n = sizeof(arr)/sizeof(arr[0]);
            
            cout << minDel(arr, n) << endl;
            break;
        }

        case 2:
        {
            //EXAMPLE 1
            int arr[] = {3, 20, 4, 6, 7, 30};
            //EXAMPLE 2
            // int arr[] = {5, 10, 20};
            //EXAMPLE 3
            // int arr[] = {20, 10, 5};

            int n = sizeof(arr)/sizeof(arr[0]);

            cout << maxSumIS(arr, n) << endl;
            break;
        }

        case 3:
        {
            //EXAMPLE 1
            // int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
            //EXAMPLE 2
            // int arr[] = {12, 11, 40, 5, 3, 1};
            //EXAMPLE 3
            // int arr[] = {30, 20, 10};
            //EXAMPLE 4
            // int arr[] = {10, 20, 30};
            //EXAMPLE 5
            int arr[] = {20, 7, 9, 6, 9, 21, 12, 3, 12, 16, 1, 27};

            int n = sizeof(arr)/sizeof(arr[0]);
            //REFER GFGPROBLEM FOLDER FOR BITONIC SUBSEQUENCE AS THERE IS SOME ERROR IN O(NLOGN) APPROACH!!
            cout << maxLenBiotonicSub(arr, n) << endl;
            break;
        }
        
        default:{
            cout << "NOT A VALID OPTION!!" << endl;
            exit(0);
        }
    }

    return 0;
}