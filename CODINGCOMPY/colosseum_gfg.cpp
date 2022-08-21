// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int j=1, num1=4;

//     while(++j<=10)
//     {
//         num1++;
//     }

//     cout << num1;
// }

// { Driver Code Starts
// Initial Template for C++

// https://practice.geeksforgeeks.org/viewSol.php?subId=ef783cf326d83d0dd1e565c7ffd0bce5&pid=711245&user=adityamk43
// https://practice.geeksforgeeks.org/viewSol.php?subId=ce85284e1ce37948b5a96721fea0c1e4&pid=711244&user=adityamk43
//https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/instructions/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve1(int N, int a, vector<int> x)
    {
        // code here
        int max = INT_MIN, secondmax = INT_MIN;
        int temp1, temp2, sum = 0;

        if (x[a] > x[a + 1])
        {
            max = x[a];
            secondmax = x[a + 1];
        }
        else
        {
            max = x[a + 1];
            secondmax = x[a];
        }

        sum = max + secondmax;

        for (int i = a + 2; i < N; i++)
        {
            if (x[i] > max && sum <= (max + secondmax))
            {
                secondmax = max;
                max = x[i];
            }
            else if (x[i] > secondmax && x[i] <= max && sum <= (max + secondmax))
                secondmax = x[i];

            sum = max + secondmax;
        }

        // cout << "gp1 max: " << max << " gp1 secondmax: " << secondmax << endl;

        return sum;
    }

    int solve2(int N, int a, vector<int> x)
    {
        // code here
        int max = INT_MAX, secondmax = INT_MAX;
        int temp1, temp2, sum = 0;

        if (x[a] < x[a + 1])
        {
            max = x[a];
            secondmax = x[a + 1];
        }
        else
        {
            max = x[a + 1];
            secondmax = x[a];
        }

        sum = max + secondmax;

        for (int i = a + 2; i < N; i++)
        {
            if (x[i] < max && sum >= (max + secondmax))
            {
                secondmax = max;
                max = x[i];
            }
            else if (x[i] < secondmax && x[i] >= max && sum >= (max + secondmax))
                secondmax = x[i];

            sum = max + secondmax;
        }

        // cout << "gp2 max: " << max << " gp2 secondmax: " << secondmax << endl;

        return sum;
    }

    long long colosseum(int N, vector<int> A)
    {

        // sort(A.begin(), A.end());

        int max = INT_MIN, secondmax = INT_MIN;
        long sum1 = 0, sum2 = 0;

        sum1 = solve1(3 * N / 2, 0, A);
        sum2 = solve2(3 * N, N + 1, A);

        // long gp1 = A[0] + A[1];
        // long gp2 = A[3*N-1] + A[3*N-2];

        // cout << sum1 << endl << sum2 << endl;
        long sum = sum1 - sum2;

        return sum;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Solution obj;
        int n;
        cin >> n;
        vector<int> a(3 * n);
        for (int i = 0; i < 3 * n; ++i)
        {
            cin >> a[i];
        }
        cout << obj.colosseum(n, a) << "\n";
    }
    return 0;
}
// } Driver Code Ends