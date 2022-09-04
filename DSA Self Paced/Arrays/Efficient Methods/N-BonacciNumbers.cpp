/**
 * @file N-BonacciNumbers.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04 11:59PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
    TIME COMPLEXITY: O(m)
    AUXILIARY SPACE: O(m)
*/

/*
    N-Bonacci Series using Sliding Window Technique
*/

void bonacciSeries(int n, int m)
{
    int a[m] = {0};

    a[n-1] = 1;
    a[n] = 1;

    for (int i=n+1; i<m; i++)
        a[i] = 2*a[i-1] - a[i-n-1];

    for (int i=0; i<m; i++)
        cout << a[i] << " ";

}

int main()
{
    int n = 5, m = 15;
    
    bonacciSeries(n, m);

    return 0;
}