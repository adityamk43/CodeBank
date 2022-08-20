/**
 * @file ReduceArraytoZero.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Given an array of N positive integers, you need to perform certain number of reduce operations on it, until all the elements become 0.

In each reduce operation, you need to find the non-zero minimum element of the array, then reduce the value of each array element by the value of that minimum element.

Note: An element can only be reduced if its value ≥ 1.

Complete the reduceArray() function in the editor. Your function must perform reduce operations on the array elements until each one of them is reduced to 0, and finally return an integer array, where ith element of the returned array denotes the number of elements reduced during the ith operation.

Input Format:

First line contains an integer i.e. N denoting number of elements.
Next N lines, contains an integer each denoting the value of ith element.
Output Format:

Print the number of elements reduced during each operation in new lines.
Constraints:

1 <= N <= 10^5
1 <= arr[i] <= 10^9
Sample Input 1

6  // N
7
3
3
1
1
9
Sample Output 1

6
4
2
1
Explanation 1

N = 6, arr = {7, 3, 3, 1, 1, 9}
Reduce Operation 0: The smallest element in arr is 1,
                 After reducing each array element in arr by 1, arr1 = {6, 2, 2, 0, 0, 8} and we print 6 (the number of elements reduced during the reduce operation) on a new line.
Reduce Operation 1: The smallest element in arr1 = {6, 2, 2, 0, 0, 8} is 2,
                 After reducing each array element in arr1 by 2, arr2 = {4, 0, 0, 0, 0, 6} and we print 4(the number of elements reduced during the reduce operation) on a new line.
Reduce Operation 2: The smallest element in arr2 = {4, 0, 0, 0, 0, 6} is 4,
                 After reducing each array element in arr2 by 4, arr3 = {0, 0, 0, 0, 0, 2} and we print 2(the number of elements reduced during the reduce operation) on a new line.
Reduce Operation 3: The smallest element in arr3 = {0, 0, 0, 0, 0, 2} is 2,
                 After reducing each array element in arr3 by 2, arr4 = {0, 0, 0, 0, 0, 0} and we print 1(the number of elements reduced during the reduce operation) on a new line.
At this point, there are no more elements to be reduced and we cease performing reduce operations.
Sample Input 2

8  // N
1
2
3
4
3
3
2
1
Sample Output 2

8
6
4
1
 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solution Approach 2 - Using Sorting
 
Initially we are given N sticks. After each cut operation the length of each remaining stick will be reduced by the length(non zero) of the smallest stick, say minStick. So all the sticks with length minStick will disappear, and the number of remaining sticks will reduce.

Therefore, the idea is to sort the sticks based on their lengths, in the ascending order. After sorting all the same length sticks will come together, so counting them will become easy. Now traverse the sorted array, and in each iteration reduce the number of remaining sticks with the count of the current smallest stick.	

Time Complexity: O(n*log(n)) ; Sorting an array takes n*log(n) time.

Space Complexity: O(1)
 * 
 */

/*
#include <bits/stdc++.h>
using namespace std;

void cutTheSticks(int lengths[], int n)
{
    int remainingSticks = n;
    sort(lengths, lengths + n);
    
    for(int i=0; i<n; i++)
    {
        cout << remainingSticks << " ";
        int count = 1;
        while (i+1 < n && lengths[i] == lengths[i+1])
        {
            count++;
            i++;
        }
        remainingSticks -= count;
    }
}

int main()
{
    int lengths[] = {5, 4, 4, 2, 2, 8};
    int n = sizeof(lengths) / sizeof(lengths[0]);
    
    cutTheSticks(lengths, n);

    return 0;
}
*/

/**
 * @brief Solution Approach 1
 
The simple solution is, unless the remaining sticks become zero, everytime find the length(non zero) of the shortest stick and reduce the length of all the remaining sticks with that value. Before each cut operation print the number of remaining sticks, and also keep track of the remaining sticks after each cut operation.

Time Complexity: O(n^2)

Space Complexity: O(1)
 * 
 */
/*
 * Complete the function below with 1 argument:
 *   An integer array of positive integers
 *
 * Return an array which denotes the number of elements reduced during ith operation
 */

vector<int> reduceArray(vector<int> arr)
{
    // Write your code here

    vector<int> res;
    int count = arr.size(), rem;
    int min;
    int k = 0;

    while (count > 0)
    {
        // cout << endl << "NEW LOOP";
        res.push_back(count);

        min = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < min && arr[i] != 0)
            {
                min = arr[i];
            }
        }

        // cout << endl << "MIN: " << min << endl;

        count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] != 0)
            {
                arr[j] = arr[j] - min;
                // cout << arr[j] << endl;
                if (arr[j] != 0)
                    count++;
                // cout << " count: " << count << endl;
            }
        }

        // res.push_back(count);
    }

    return res;
}
int main()
{
    int n = 0, i;
    cin >> n;

    vector<int> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> res;
    res = reduceArray(arr);
    for (i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}

/*
100
77
69
93
90
71
91
96
98
78
65
68
79
89
100
70
93
70
94
79
97
70
76
84
81
72
93
94
100
97
96
93
73
69
73
79
93
89
70
94
81
91
88
82
99
91
72
70
93
93
77
89
73
65
86
72
81
94
66
78
90
98
85
96
83
81
94
94
93
89
70
65
94
92
85
71
70
99
86
98
79
93
79
72
99
68
81
85
99
66
76
82
87
77
77
84
97
88
86
99
79
*/
// #include <math.h>
// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>

// /*
//  * Complete the function below with 3 arguments:
//  *   Size of the array.
//  *   An integer array of positive integers.
//  *   Pointer to the variable which is used to store the size of the result array.
//  *
//  * Return an array which denotes the number of elements reduced during ith operation
//  */

// int *reduceArray(int arr_size, int arr[], int *result_size)
// {
//     // Write your code here
//     int res[30], sum_count;
//     int count = 0, ressize = 0;
//     int min = INT_MIN;
//     int k = 0;

//     while (arr_size != sum_count)
//     {
//         for (int i = 0; i < arr_size; i++)
//         {
//             if (arr[i] < min)
//             {
//                 min = arr[i];
//             }
//         }

//         for (int j = 0; j < arr_size; j++)
//         {
//             if (arr[j] != 0)
//             {
//                 arr[j] = arr[j] - min;
//                 count++;
//             }
//         }
//         res[k++] = count;
//         sum_count += count;
//     }

//     *result_size = k - 1;
//     int* p = res;
//     return p;
// }

// int main()
// {
//     int *res, res_size, arr_size = 0, i;
//     scanf("%d", &arr_size);

//     int arr[arr_size];
//     for (i = 0; i < arr_size; i++)
//         scanf("%d", &arr[i]);

//     res = reduceArray(arr_size, arr, &res_size);
//     for (i = 0; i < res_size; i++)
//         printf("%d\n", res[i]);

//     return 0;
// }