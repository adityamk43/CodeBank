/**
 * @file LongestSpanWithSameSum.cpp
 * @author Aditya Bhardwaj
 * @brief https://www.geeksforgeeks.org/longest-span-sum-two-binary-arrays/
 * @version 0.1
 * @date 2022-08-20 3:10PM IST
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int longestSpan(bool arr1[], bool arr2[], int n)
{
    int auxArray[2*n +1];

    int maxLen = 0;

    int preSum1 = 0;
    int preSum2 = 0;
    
    int cur_Diff = 0;
    int diffIndex = 0;

    memset(auxArray, -1, sizeof(auxArray));

    for (int i=0; i<n; i++)
    {
        preSum1 += arr1[i];
        preSum2 += arr2[i];

        cur_Diff = preSum1 - preSum2;

        diffIndex = n + cur_Diff;

        if (cur_Diff == 0)
            maxLen = i + 1;
        
        else if (auxArray[diffIndex] == -1)
            auxArray[diffIndex] = i;
        
        else 
        {
            int len = i - auxArray[diffIndex];

            if (len > maxLen)
                maxLen = len;
        }
    }

    return maxLen;
}


int main()
{
    bool arr1[] = {0, 1, 0, 1, 1, 1, 1};
    bool arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    cout << longestSpan(arr1, arr2, n) << endl;

    return 0;
}