#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

/* FOR ARRAY REVERSE USE THESE FUNCTION ELSE FOR VECTOR IMPLEMENTATION IS ALREADY DONE */
// int min(int x, int y)
// {
//     return (x < y) ? x : y;
// }

// void reverse(vector<int> arr, int l, int r)
// {
//     int temp;

//     while (l < r)
//     {
//         temp = arr[l];
//         arr[l] = arr[r];
//         arr[r] = temp;

//         l++;
//         r--;
//     }
// }

vector<int> reverseSubarray(vector<int> arr, int k)
{
    // Write your code here
    vector<int> revarr;

    int i = 0;
    // reverse(arr.begin() + i, arr.begin() + k + 1);

    while (i < arr.size())
    {
        reverse(arr.begin() + i, arr.begin() + i + k);
        i = i + k;

        if ((i + k) > (arr.size() - 1))
            break;
    }

    //cout << i;

    if (i < (arr.size()-1))
    {
        reverse(arr.begin() + i, arr.end());
    }

    return arr;
}

int main()
{
    int i, n, k;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    vector<int> res;
    res = reverseSubarray(arr, k);
    for (i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}