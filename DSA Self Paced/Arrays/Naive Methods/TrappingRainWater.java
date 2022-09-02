/**
 * @file TrappingRainWater.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * @version 0.1
 * @date 2022-09-03 02:15AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

public class TrappingRainWater {

    /*
     * TIME COMPLEXITY: O(n^2)
     */
    static int getWater(int arr[]) {
        int res = 0;

        // as corner bars cannot store water so we traverse between then i=1 to i=n-2
        for (int i = 1; i < arr.length - 1; i++) {
            // finding max bar on left of arr[i]
            int lmax = arr[i];
            for (int j = 0; j < i; j++)
                lmax = Math.max(lmax, arr[j]);

            // finding max bar on right of arr[i]
            int rmax = arr[i];
            for (int j = i + 1; j < arr.length; j++)
                rmax = Math.max(rmax, arr[j]);

            // adding total water collected
            res += Math.min(rmax, lmax) - arr[i];
        }

        return res;
    }

    public static void main(String[] args) {
        int arr[] = { 3, 0, 1, 2, 5 };
        // int arr[] = {2, 0, 2};
        // int arr[] = {1, 2, 3};
        // int arr[] = {3, 2, 1};

        System.out.println(getWater(arr));
    }
}
