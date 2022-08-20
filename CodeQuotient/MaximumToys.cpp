/**
 * @file MaximumToys.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Buy maximum toys possible star_border
Amit wants to buy some toys for his sister. He has X rupees in his pocket. But he is confused to buy which toy and seeking your help.

Given an array consisting of cost of toys. Find the maximum number of toys he can buy with the amount X.

Note: He can buy only 1 quantity of a particular toy.

Input Format:

First Line will contain an integer denoting the Money available.
Second Line will contain an integer N denoting the total number of toys.
Third line contains N integers separated by space as costs.
Constraints:

1 <= X <= 10^9
1 <= N <= 10^5
1 <= cost[i] <= 10^9
Output Format:

Print the number of toys.
Sample Input

10
5
10 4 1 17 5
Sample Output

3
Explanation:

Amit can buy toy number 2, 3 and 5 which costs him 4+1+5=10 Rupees and fits in his budget.



 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

int maxToys(int cost[], int n, int X)
{
    // Write your code here
    int sum = X;
    int count = 0;

    sort(cost, cost + n);

    for (int i = 0; i < n; i++)
    {
        if (sum < cost[i])
            break;

        sum -= cost[i];
        count++;
    }

    return count;
}
int main()
{
    int i, n, sum;
    cin >> sum >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << maxToys(a, n, sum);
    return 0;
}