// #include <bits/stdc++.h>

// using namespace std;

// class Solution
// {
// public:
//     void solve(int N, vector<int> &v, vector<long long> &pre, vector<long long> &suff)
//     {
//         priority_queue<int, vector<int>, greater<int>> pq1;
//         priority_queue<int> pq2;
//         long long sum = 0;
//         for (int i = 0; i < 2 * N; i++)
//         {
//             sum += v[i];
//             pq1.push(v[i]);
//             if (i < N - 1)
//                 continue;
//             if (i == N - 1)
//                 pre[i] = sum;
//             else if (i >= N)
//             {
//                 sum = sum - pq1.top();
//                 pq1.pop();
//                 pre[i] = sum;
//             }
//         }
//         sum = 0;
//         for (int i = 3 * N - 1; i >= N; i--)
//         {
//             sum += v[i];
//             pq2.push(v[i]);
//             if (i > 2 * N)
//                 continue;
//             if (i == 2 * N)
//                 suff[i] = sum;
//             else if (i <= 2 * N - 1)
//             {
//                 sum = sum - pq2.top();
//                 pq2.pop();
//                 suff[i] = sum;
//             }
//         }
//     }
//     long long colosseum(int N, vector<int> v)
//     {
//         vector<long long> pre(3 * N, 0), suff(3 * N, 0);
//         solve(N, v, pre, suff);
//         long long ans = INT_MIN;
//         for (int i = N - 1; i < 2 * N; i++)
//             ans = max(ans, pre[i] - suff[i + 1]);
//         return ans;
//     }
// };

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void solution(vector<long long> &first, vector<long long> &second, int N, vector<int> &v)
    {
        priority_queue<int, vector<int>, greater<int>> max;
        priority_queue<int> secondmax;

        long long sum = 0;

        for (int i = 0; i < 2 * N; i++)
        {
            sum = sum + v[i];
            max.push(v[i]);

            if (i < N - 1)
                continue;
            else if (i >= N)
            {
                sum = sum - max.top();
                max.pop();
                first[i] = sum;
            }
            else if (i == N - 1)
                first[i] = sum;
        }

        sum = 0;

        for (int i = 3 * N - 1; i >= N; i--)
        {
            sum += v[i];

            secondmax.push(v[i]);

            if (i > 2 * N)
                continue;
            else if (i <= 2 * N - 1)
            {
                sum = sum - secondmax.top();
                secondmax.pop();
                second[i] = sum;
            }
            else if (i == 2 * N)
                second[i] = sum;
        }
    }
    long long colosseum(int N, vector<int> v)
    {
        vector<long long> first(3 * N, 0), second(3 * N, 0);

        solution(first, second, N, v);

        long long total_strength = INT_MIN;

        for (int i = N - 1; i < 2 * N; i++)
            total_strength = max(total_strength, first[i] - second[i + 1]);

        return total_strength;
    }
};

// { Driver Code Starts.
// https://practice.geeksforgeeks.org/viewSol.php?subId=ef783cf326d83d0dd1e565c7ffd0bce5&pid=711245&user=adityamk43
// https://practice.geeksforgeeks.org/viewSol.php?subId=ce85284e1ce37948b5a96721fea0c1e4&pid=711244&user=adityamk43
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