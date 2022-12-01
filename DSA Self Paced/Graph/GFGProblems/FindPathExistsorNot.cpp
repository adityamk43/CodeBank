/**
 * @file FindPathExistsorNot.cpp
 * @author ADITYA BHARDWAJ
 * @brief Find whether path exist
MediumAccuracy: 45.09%Submissions: 66043Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.


Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0
3 0 0 0 3
3 3 3 3 3
0 2 3 0 0
3 0 0 1 3
There is no path to reach at (3,1) i,e at
destination from (4,3) i,e source.
Example 2:

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1)
i,e destination.


Your Task:
You don't need to read or print anything. Your task is to complete the function is_Possible() which takes the grid as input parameter and returns boolean value 1 if there is a path otherwise returns 0.


Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)


Constraints:
1 ≤ n ≤ 500
 * @version 0.1
 * @date 2022-12-01 10:00 PM
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
    // Function to find whether a path exists from the source to destination.
    bool myDFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return false;

        if (grid[i][j] == 2)
            return true;

        grid[i][j] = 0;

        if (
            myDFS(grid, i + 1, j) == true ||
            myDFS(grid, i - 1, j) == true ||
            myDFS(grid, i, j + 1) == true ||
            myDFS(grid, i, j - 1) == true)
        {
            return true;
        }

        else
            return false;


        //My Method (Above one is better in a way of readability. My is somewhat same but readability can be uneasy for few)
        // if (i<0 || i>=grid.size() || j<0 || j>=grid[i].size())
        //     return false;
            
        // if (grid[i][j] == 2)
        //     return true;
        
        // else if (grid[i][j] == 3 || grid[i][j] == 1)
        // {
        //     grid[i][j] = 4;
                
        //     if (
        //         myDFS(grid, i+1, j) == true ||
        //         myDFS(grid, i-1, j) == true ||
        //         myDFS(grid, i, j+1) == true ||
        //         myDFS(grid, i, j-1) == true 
        //     )
        //     {
        //         return true;
        //     }   
        // }
        // else
        //     return false;
    }

    bool is_Possible(vector<vector<int>> &grid)
    {
        // code here
        int source_i, source_j;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    source_i = i;
                    source_j = j;
                }
            }
        }

        // cout << source_i << ":" << source_j << endl;

        return myDFS(grid, source_i, source_j);

        // return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        bool ans = obj.is_Possible(grid);
        cout << ((ans) ? "1\n" : "0\n");
    }
    return 0;
}
// } Driver Code Ends