/**
 * @file KClosestElements.cpp
 * @author ADITYA BHARDWAJ
 * @brief Print K Closest Elements to the given value in an array
 * @version 0.1
 * @date 2022-11-19 07:32 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>
using namespace std;

/**
 * @brief TIME COMPLEXITY: ⊝(nk)
 *        AUXILIARY SPACE: O(n) for bool visited array
 * 
 * Example:
 * arr[] = { 10,30,5,40,38,80,70 }
 * x = 35
 * k = 3
 * 
 * i=0: min_diff = 3
 *      min_diff_idx = 4
 *      print(38)
 * i=1: min_diff = 5
 *      min_diff_idx = 3
 *      print(40)
 * i=2: min_diff = 5
 *      min_diff_idx = 1
 *      print(30)
 * 
 * @param arr 
 * @param n 
 * @param k 
 * @param x 
 */
// void printKClosest(int arr[], int n, int k, int x)
// {
//     bool visited[n]={false};
    
//     for(int i=0;i<k;i++){
        
//         int min_diff=INT_MAX;
//         int min_diff_idx;
        
//         for(int j=0;j<n;j++){
//             if(visited[j]==false && abs(arr[j]-x)<=min_diff){
//                 min_diff=abs(arr[j]-x);
//                 min_diff_idx=j;
//             }
//         }
//         cout<<arr[min_diff_idx]<<" ";
//         visited[min_diff_idx]=true;
//     }
// }


/**
 * @brief Optimised Version Using Approach of K Largest Elements but instead we will use it to do K smallest Elements to store small differences upto k to find k closest elements of given number x
 * 
 * TIME COMPLEXITY: O(nlogk)
 * 
 * Even Suppose we want to print in sorted order, we will have to sort the value and then print which will also take O(nlogk)
 * @param arr 
 * @param n 
 * @param k 
 * @param x 
 */
void printKClosest(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> pq;

    //O(klogk)
    for (int i=0; i<k; i++)
        pq.push({abs(arr[i]-x), arr[i]});

    //O((n-k)logk)
    for (int i=k; i<n; i++)
    {
        int diff = abs(arr[i]-x);
        if (pq.top().first > diff)
        {
            pq.pop();
            pq.push({diff, arr[i]});
        }
    }

    //O(logk)
    while (!pq.empty())
    {
        cout << pq.top().second << " ";
        pq.pop();
    }
    cout << endl;

}

int main()
{

	int arr[] = { 10,30,5,40,38,80,70 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int x=35; int k = 3;

	printKClosest(arr,size,k,x);

	return 0;
}
