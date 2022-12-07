/**
 * @file FractionalKnapsack.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * Fractional Knapsack problem:-
 * 
 * The problem states that:

Given a list of elements with specific values and weights associated with them, the task is to fill a Knapsack of weight W using these elements such that the value of knapsack is maximum possible.

Note: You are allowed to take a fraction of an element also in order to maximize the value.

The local optimal strategy is to choose the item that has maximum value vs weight ratio. This strategy also leads to global optimal solution because we are allowed to take fractions of an item.

[In general, the Greedy Algorithm can be applied to solve a problem if it satisfies the below property:

At every step, we can make a choice that looks best at the moment, and we get the optimal solution of the complete problem.]

 * @version 0.1
 * @date 2022-12-07 10:36 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

bool MyCmp(pair<int, int> &I1, pair<int, int> &I2)
{  
    //Value/Weight Ratio
    double r1 = (double) I1.first/I1.second;
    double r2 = (double) I2.first/I2.second;

    return r1 > r2;
}

/**
 * @brief TIME COMPLEXITY: O(nlogn)
 *        AUX SPACE: O(1) as we are not creating array
 * @param arr 
 * @param n 
 * @param W 
 * @return double 
 */
double fknapS(pair<int, int> arr[], int n, int W)
{
    //O(nlogn)
    sort(arr, arr+n, MyCmp);

    double res=0.0;

    //O(n)
    for (int i=0; i<n; i++)
    {
        if (arr[i].second <= W)
        {
            //adding Value
            res+= arr[i].first;
            //subtracting item's weight
            W -= arr[i].second;
        }
        else
        {
            res += arr[i].first * ((double)W/arr[i].second);
            break;
        }
    }

    return res;
}

int main()
{
    pair<int, int> arr[] = {make_pair(120, 30), make_pair(100, 20), make_pair(60, 10)};
    int n = sizeof(arr)/sizeof(arr[0]);
    int W=50;

    cout << fknapS(arr, n, W) << endl;

    return 0;
}