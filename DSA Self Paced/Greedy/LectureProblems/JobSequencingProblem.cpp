/**
 * @file JobSequencingProblem.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 *                          Job Sequencing Problem | Greedy Approach
 * 
 * Problem: Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.
 * 
 * This is a standard Greedy Algorithm problem. Following is the greedy algorithm to solve the above problem:
    1) Sort all jobs in decreasing order of profit.

    2) Initialize the result sequence as the first job in sorted jobs.

    3) Do following for remaining n-1 jobs:
        a) If the current job can fit in the current result sequence without missing the deadline, add the current job to the result.
        b) Else ignore the current job.
 * 
 * @version 0.1
 * @date 2022-12-08 03:04 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> Job;

bool myCmp(Job &j1, Job &j2)
{
    return j1.second > j2.second;
}

/**
 * @brief Time Complexity: O(n^2)
 * 
 * Time Complexity of the above solution is O(n2). It can be optimized using Disjoint Set Data Structure. Please refer below post for details.
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int maxProfitJobSequencing(Job arr[], int n)
{
    sort(arr, arr+n, myCmp);

    int res=0;
    bool slot[n];

    for (int i=0; i<n; i++)
        slot[i] = false;

    for (int i=0; i<n; i++)
    {
        for (int j=min(n, arr[i].first)-1; j>=0; j--)
        {
            if (slot[j] == false)
            {
                res+=arr[i].second;
                slot[j] = true;
                break;
            }
        }
    }

    return res;
}

int main()
{
    Job arr[] = { 
        make_pair(4, 50),
        make_pair(1, 5),
        make_pair(1, 20),
        make_pair(5, 10),
        make_pair(5, 80)
    };
                
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Following is maximum profit sequence of job : ";
    
    cout << maxProfitJobSequencing(arr, n) << endl;

    return 0;
}