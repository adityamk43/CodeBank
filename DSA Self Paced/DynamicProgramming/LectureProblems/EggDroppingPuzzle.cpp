/**
 * @file EggDroppingPuzzle.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * This problem is about Egg Dropping Puzzle where we are given number of floors and number of eggs and with those eggs we need to take trials on from which floor will the eggs will break or in a certain way we can say that if the egg breaks at certain floor then it is not sure that it will break from below floors.
 * 
 * Basically we need to find the threshold value for egg breaking floor in worst case. There will be no threshold value if egg doesn't break on any of the given number of floors.
 * 
 * @version 0.1
 * @date 2022-12-24 08:56 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief PLAIN RECURSION
 * 
 * TIME COMPLEXITY: Exponential as either the eggs break or doesn't break at certain floor
 * AUXILIARY SPACE: O(1) As there was no use of any data structure for storing values.
 * 
 * @param f 
 * @param e 
 * @return int 
 */
// int eggDrop(int f, int e)
// {
//     // As for 1 egg, we will need to take trials for all floors
//     if (e==1)
//         return f;
    
//     //If there is no floor, then there is no need to check
//     if (f==0)
//         return 0;
    
//     //For 1 floor obviously 1 trial is needed
//     if (f==1)
//         return 1;
    
//     int res=INT_MAX;

//      //We take max of these as we want to find worst case of egg drop!! 
//     for (int i=1; i<=f; i++)
//         res = min(res, 1+max(eggDrop(i-1, e-1), eggDrop(f-i, e)));

//     return res;
// }

/**
 * @brief D.P. TABULATION TECHNIQUE
 * (Refer recursive approach above for understanding approach and idea)
 * TIME COMPLEXITY: O(f^2 e)
 * AUXILIARY SPACE: O(fe)
 * 
 * @param f 
 * @param e 
 * @return int 
 */
int eggDrop(int f, int e)
{
    //we could have used dp[f+1][e] as dp array but for simplicity and easy understanding we add plus 1 below for e dimension.
    int dp[f+1][e+1];

    //ignoring first column dp[0][e+1] since, we don't need that column values and hence we ignore those since, we discussed above that we take e+1 as a dimension and hence we have extra column here to ignore!!
    for (int i=1; i<=f; i++)
        for (int j=1; j<=e; j++)
            dp[i][j]=INT_MAX;
    

    for (int i=1; i<=f; i++)
        dp[i][1] = i;
    
    for (int j=1; j<=e; j++)
    {
        dp[0][e] = 0;
        dp[1][e] = 1;
    }
    
    for (int i=2; i<=f; i++)
    {
        for (int j=2; j<=e; j++)
        {
            for (int x=1; x<=i; x++)
            {
                dp[i][j] = min(dp[i][j], 1+max(dp[x-1][j-1], dp[i-x][j]));
            }
        }
    }

    return dp[f][e];

}

int main()
{
    int f=10, e=2;

    cout << eggDrop(f, e) << endl;

    return 0;
}