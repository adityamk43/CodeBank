/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 23
 * @author ADITYA BHARDWAJ
 * 22/08/2023 11:30 AM
 * 
 * @description
 * 121. Best Time to Buy and Sell Stock
    Easy
    27.7K
    916
    Companies
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    

    Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
    Example 2:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.
    

    Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104
    Accepted
    3.7M
    Submissions
    6.8M
    Acceptance Rate
    53.7%

 * @returns
    Accepted

    Runtime
    Details
    76ms
    Beats 78.60%of users with TypeScript

    Memory
    Details
    51.01MB
    Beats 97.28%of users with TypeScript
 */

// My Approach
// function maxProfit(prices: number[]): number {

//     let buy: number = prices[0];
//     let sell: number = prices[1];

//     let maxProfit: number = 0;

//     let lpt: number = 0, rpt: number = 1;

//     while (rpt!==prices.length && lpt <= rpt) {
//         if (buy <= sell) {
//             maxProfit = Math.max(maxProfit, sell - buy);
//             sell = prices[++rpt];
//         }
//         else if (buy > sell)
//             buy = prices[++lpt];
//     }

//     return maxProfit;
// };

// More Space Optimised Approach
function maxProfit(prices: number[]): number {
  let buy: number = prices[0];
  let maxProfit: number = 0;

  let i = 1;
  while (i < prices.length) {
    if (buy > prices[i]) buy = prices[i];
    else maxProfit = Math.max(maxProfit, prices[i] - buy);

    i++;
  }

  return maxProfit;
}

// Test Cases

//Case 1
let prices:number[]=[7,1,5,3,6,4];

//Case 2
// let prices:number[]=[7,6,4,3,1];

//Case 3
// let prices:number[]=[7,3,5,1,6,4];

console.log(maxProfit(prices));