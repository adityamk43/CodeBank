/**
 * @file FractionalKnapSack.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * 
 * Fractional Knapsack problem:-
 * 
 * The problem states that:

Given a list of elements with specific values and weights associated with them, the task is to fill a Knapsack of weight W using these elements such that the value of knapsack is maximum possible.

Note: You are allowed to take a fraction of an element also in order to maximize the value.

The local optimal strategy is to choose the item that has maximum value vs weight ratio. This strategy also leads to global optimal solution because we are allowed to take fractions of an item.

[In general, the Greedy Algorithm can be applied to solve a problem if it satisfies the below property:

At every step, we can make a choice that looks best at the moment, and we get the optimal solution of the complete problem.]

 * @version 0.1
 * @date 2022-12-07 11:06 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

import java.util.*;

class Item implements Comparable<Item> {
    int wt;
    int val;

    Item(int w, int v) {
        wt = w;
        val = v;
    }

    public int compareTo(Item i) {
        return wt * i.val - val * i.wt;
    }

}

class FractionalKnapSack {

    /**
     * TIME COMPLEXITY: O(nlogn)
     * AUX SPACE: O(1) as we are not creating array
     * @param arr
     * @param n
     * @param W
     * @return
     */
    static double fracKnapSack(Item arr[], int n, int W) {

        //O(nlogn)
        Arrays.sort(arr);

        double res = 0.0;

        //O(n)
        for (int i = 0; i < n; i++) {
            if (arr[i].wt <= W) {
                res += arr[i].val;

                W = W - arr[i].wt;
            } else {
                res += arr[i].val * ((double) W / arr[i].wt);

                break;
            }
        }

        return res;
    }

    public static void main(String args[]) {
        Item arr[] = { new Item(10, 60),
                new Item(40, 40),
                new Item(20, 100),
                new Item(30, 120) };

        int n = 4, W = 50;

        System.out.println(fracKnapSack(arr, n, W));

    }

}