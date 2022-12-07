/**
 * @file GreedyIntro.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * Introduction to Greedy Algorithms

Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. So the problems where choosing locally optimal also leads to the global optimal solution are best fit for Greedy.

For example, consider the Fractional Knapsack Problem. The problem states that:

Given a list of elements with specific values and weights associated with them, the task is to fill a Knapsack of weight W using these elements such that the value of knapsack is maximum possible.

Note: You are allowed to take a fraction of an element also in order to maximize the value.


The local optimal strategy is to choose the item that has maximum value vs weight ratio. This strategy also leads to global optimal solution because we are allowed to take fractions of an item.

In general, the Greedy Algorithm can be applied to solve a problem if it satisfies the below property:

At every step, we can make a choice that looks best at the moment, and we get the optimal solution of the complete problem.

GENERAL STRUCTURE OF GREEDY ALGORITHMS:

getOptimal(Item arr[], int n)
{
    1.) Initialise: res=0

    2.) while(All items are not considered )
        {
            [Select can be min/max item like Dijsktra/Prim's or we can either preprocess before like sorting as we din in coins problems below]
            i = selectAnItem() 

            if (feasible(i))
                res = res + i
        }

    3.) return res
}

IMPORTANT NOTE: GREEDY ALGORITHMS MAY NOT WORK ALWAYS!!

Consider:

If we provide some random values of coins, it doesn't work!
It only works if we provide Indian or US currency values!
    coins[] = {18, 1, 10}
    amount = 20
Greedy will give: 
    1 coin of 18
    2 coins of 1
But optimal should be
    2 coins of 10!!

Another Example: Longest Path
                (2)
            A -------- D
    (10) /             \ (1)
            (1) (20) (5)
    Source -- B -- E --- Destination
    (2)  \       / (5)
            C 
    
    Optimal Solution according to Prim's/Dijsktra (Greedy Algorithms) for Longest Path:
        10 -> 2 -> 1 = 13
    
    But Optimal should be:
        1 -> 20 -> 5 = 26!!

=>Applications of greedy algorithms:

    1.) Finding Optimal Solutions:
        -> Activity Selection
        -> Fractional Knapsack
        -> Job Sequencing
        -> Prims' Algroithm
        -> Kruskal's Algorithm
        -> Dijsktra's Algorithm
        -> Huffman Coding (optimal lossless compression technique)
    
    2.) Finding close to optimal Solution's fo NP Hard Problems like Travelling Salesman Problem.
        (For this algorithn greedy produce optimal solution but useful)

        NOTE: NP Hard Problems are problems in Computer Science for which no polynomial time exists and it has not been proved also that there cannot be a polynomial time solution and these problems exist a lot in real world. And if we write an exponential time for those problems that's going to cause lots of computation time and computation resources and making these exponential Solutions infeasible practically. So, for those problems greedy algorithms are used to provide a solution which is close to Optimal. For example, Travelling Salesman Problem which is a NP Hard Problem. If we tried the perfect solution which always give us the optimal solution that solution is going to take exponential time which is not practically feasible because it may take hours even for slightly larger input. So, what we do is we write a solution that provides optimal solution within bounds. So, we say that if optimal solution is X, then this greedy solution is never going to give you value more than 2X.

    SO, THESE ARE THE ALGORITHMS WHERE GREEDY IS USEFUL TO PROVIDE SUB OPTIMAL SOLUTIONS WITHIN CERTAIN BOUNDS.


 * @version 0.1
 * @date 2022-12-07 07:06 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
  * @brief Problem: Minimum number of coins to pay some amount!!
  * 
  * Consider infinite supply of the following value coins
  * 10 5 2 1
  * If someone asks for an amount, how will you give this amount using minimum number of coins?
  * 
  * Example:
  * Amount: 52
  * 
  * We take 5 coins of 10 Rs
  * Take 1 coin of 2 Rs 
  * 
  */
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/**
 * @brief TIME COMPLEXITY: O(n)
 *        AUX SPACE: O(1)
 * 
 * @param coins 
 * @param n 
 * @param amount 
 * @return int 
 */
int minCoins(int coins[], int n, int amount)
{
    //sorting the coins in decreasing order of their value
    sort(coins, coins+n, greater<int>());

    //variable to add number of coins needed for paying given amount
    int res = 0;

    //picking optimal coin and how much optimal number of that coin value is needed at each steps of traversal
    for (int i=0; i<n; i++)
    {
        if (coins[i] <= amount)
        {
            int c = floor(amount/coins[i]);

            res += c;
            
            amount -= c*coins[i];
        }

        if (amount == 0)
            break;
    }

    return res;
}

int main()
{
    int coins[] = {5, 10, 2, 1};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 57;

    cout << minCoins(coins, n, amount);

    return 0;
}