/**
 * @file CeilingonLeftSideofArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief find the ceiling value of left side of an array and if not present then return -1
 * @version 0.1
 * @date 2022-11-09 11:38 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <set>

using namespace std;

/**
 * @brief TIME COMPLEXITY: O(nlogn)
 *          AUX SPACE: O(n)
*/
void printCeiling(int *arr, int n)
{
    set<int> s;

    cout << -1 << " ";

    s.insert(arr[0]);

    for (int i=1; i<n; i++)
    {
        auto it = s.lower_bound(arr[i]);
        s.insert(arr[i]);

        if (it==s.end())
            cout << -1 << " ";
        else
            cout << *it << " ";
    }

    cout << endl;

}

int main()
{
    int arr[] = {2, 8, 30, 15, 25, 12};
    // int arr[] = {30, 20, 10};
    // int arr[] = {10, 20, 30};

    int n = sizeof(arr)/sizeof(arr[0]);

    printCeiling(arr, n);

    return 0;
}