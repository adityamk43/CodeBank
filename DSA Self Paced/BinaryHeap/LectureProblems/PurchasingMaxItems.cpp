/**
 * @file PurchasingMaxItems.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * We are given a cost of n elements and a sum variable.
 * We need to find Maximum number if elements that we can buy under the given sum.
 * 
 * Example:
 * I/P: cost[] = {1, 12, 5, 111, 200}
 *      sum = 10
 * O/P: 2 (1 and 5)
 * 
 * I/P: cost[] = {20, 10, 5, 30, 100}
 *      sum=35
 * O/P: 3 (5, 10, 20)
 * 
 * @version 0.1
 * @date 2022-11-19 06:39 PM
 * 
 * @copyright Copyright (c) 2022 
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * @brief Method 1(Sorting):
 * Time Complexity: O(nlogn)
 * 
 * 1.) Sort the given array
 * cost[] = {1, 5, 12, 111, 200}
 * 2.) 
 * Run a loop:
 * sum = 10, res = 0;
 * i=0: sum = 9, res = 1
 * i=1: sum = 4, res = 2
 * i=2: return res
 */
// int purchasingMaxItems(int cost[], int n, int sum)
// {
//     int res=0;
//
//     //O(nlogn)
//     sort(cost,cost+n);
//
//     //O(res)
//     for(int i=0;i<n;i++){
//         if(cost[i]<=sum){
//             sum-=cost[i];
//             res++;
//         }else{
//             break;
//         }
//     }
//
//     return res;
// }

/**
 * @brief Method 2(Using Heap)
 * 
 * We Min heapify the given array and check if the current min Element(root) is smaller than sum.
 * if it is smaller then we increment res
 * 
 * we do it till sum of root elements gets greater than sum and then return the res.
 * 
 * TIME COMPLEXITY: AVERAGE: O(n) + O(res*logn) = O(res*logn)
 *                  WORST: O(nlogn) [if we add all elements of an array]
 * 
 * @param cost 
 * @param n 
 * @param sum 
 * @return int 
 */
int purchasingMaxItems(int cost[], int n, int sum)
{
    //O(n)
    priority_queue<int, vector<int>, greater<int>> pq(cost, cost+n);

    int res = 0;

    //O(res*logn)
    while (!pq.empty())
    {
        if (pq.top() <= sum)
        {
            sum -= pq.top();
            pq.pop();
            res++;
        }
        else
            break;
    }

    return res;
}

int main()
{
    // int cost[] = {1, 12, 5, 111, 200};
    int cost[] = {20, 10, 5, 30, 100};
    int n = sizeof(cost)/sizeof(cost[0]);

    // int sum=10;
    int sum=35;

    cout << purchasingMaxItems(cost, n, sum) << endl;

    return 0;
}
