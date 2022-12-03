/**
 * @file RotAllOranges.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * Rotten Oranges
MediumAccuracy: 46.02%Submissions: 80946Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.


Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).


Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n, m ≤ 500
 *
 * @version 0.1
 * @date 2022-12-03 02:40 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> myPair;

class Solution
{
public:
    bool isdelim(pair<int, int> p)
    {
        return (p.first == -1 && p.second == -1);
    }

    bool isValid(int i, int j, int rows, int cols)
    {
        return (i >= 0 && j >= 0 && i < rows && j < cols);
    }

    bool checkAll(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    return true;
            }
        }

        return false;
    }
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here

        int rows = grid.size();
        int cols = grid[0].size();

        queue<myPair> q;
        int timeFrame = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        q.push({-1, -1});

        while (!q.empty())
        {
            bool flag = false;

            while (!isdelim(q.front()))
            {

                myPair mp = q.front();

                int i = mp.first;
                int j = mp.second;

                if (isValid(i + 1, j, rows, cols) && grid[i + 1][j] == 1)
                {
                    q.push({i + 1, j});

                    grid[i + 1][j] = 2;

                    if (!flag)
                    {
                        flag = true;
                        timeFrame++;
                    }
                }
                if (isValid(i - 1, j, rows, cols) && grid[i - 1][j] == 1)
                {
                    q.push({i - 1, j});

                    grid[i - 1][j] = 2;

                    if (!flag)
                    {
                        flag = true;
                        timeFrame++;
                    }
                }
                if (isValid(i, j + 1, rows, cols) && grid[i][j + 1] == 1)
                {
                    q.push({i, j + 1});

                    grid[i][j + 1] = 2;

                    if (!flag)
                    {
                        flag = true;
                        timeFrame++;
                    }
                }
                if (isValid(i, j - 1, rows, cols) && grid[i][j - 1] == 1)
                {
                    q.push({i, j - 1});

                    grid[i][j - 1] = 2;

                    if (!flag)
                    {
                        flag = true;
                        timeFrame++;
                    }
                }

                q.pop();
            }

            q.pop();

            if (!q.empty())
            {
                q.push({-1, -1});
            }
        }

        return (checkAll(grid) ? -1 : timeFrame);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends