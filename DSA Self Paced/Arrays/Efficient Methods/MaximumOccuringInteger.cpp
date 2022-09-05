/**
 * @file MaximumOccuringInteger.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-05 07:45 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: ⊝(n)
    AUXILIARY SPACE: O(1)
*/

int maxOccuring(int L[], int R[], int n)
{
    //we are assuming that the values in ranges will not exceed more than 1000
    vector<int> arr(1000);
    // int arr[1000];
    //In java arr has all values default as 0 so we don't need to initialise additionally or we can also use ArrayList in java
    // memset(arr, 0, sizeof(arr));

    for (int i=0; i<n; i++)
    {
        //to increment the presence of beginning of the range L[i]
        arr[L[i]]++;

        //to mark the presence of the end of the range and also to nullify the affect of increment due to beginning presence upto end value of the range in R[i]
        arr[R[i]+1]--;
    }

    int max = arr[0], res = 0;

    for (int i=1; i<1000; i++)
    {
        //doing prefix sum
        arr[i] += arr[i-1];

        if (arr[i] > max)
        {
            max = arr[i];
            res = i;
        }
    }

    return res;

}

int main()
{
    int L[] = {1, 2, 3};
    int R[] = {3, 5, 7};
    int n = sizeof(L)/sizeof(L[0]);

    cout << maxOccuring(L, R, n);

    return 0;
}