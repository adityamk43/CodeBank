/**
 * @file StepsByKnight.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Steps by Knight
MediumAccuracy: 37.32%Submissions: 81799Points: 4
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.



Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).




Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the initial position of Knight (KnightPos), the target position of Knight (TargetPos), and the size of the chessboard (N) as input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position or return -1 if its not possible.



Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).



Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
 *
 * @version 0.1
 * @date 2022-12-05 07:19 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
        int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

        queue<pair<int, pair<int, int>>> q;

        bool visited[N + 1][N + 1];

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                visited[i][j] = false;

        q.push({0, {KnightPos[0], KnightPos[1]}});
        visited[KnightPos[0]][KnightPos[1]] = true;

        while (!q.empty())
        {
            int i = q.front().second.first;
            int j = q.front().second.second;
            int dis = q.front().first;
            q.pop();

            if (i == TargetPos[0] && j == TargetPos[1])
                return dis;

            for (int k = 0; k < 8; k++)
            {
                int u = i + dx[k];
                int v = j + dy[k];

                if (u >= 1 && v >= 1 && u <= N && v <= N && !visited[u][v])
                {
                    q.push({dis + 1, {u, v}});
                    visited[u][v] = true;
                }
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends