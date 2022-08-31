/**
 * @file LargestElementInArray.java
 * @author ADITYA BHARDWAJ
 * @brief
 * @version 0.1
 * @date 2022-09-01 01:23AM
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
    TIME COMPLEXITY: O(n^2)

    Best Case: When largest element is found at first index
                ⊖(n)
    Worst Case: When largest element is found at last index
                ⊖(n^2)
*/
class LargestElementInArray {

    static int getLargest(int arr[]) {

        //Since arrays are objects in Java, we use this method and not pass size along in the function call
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            Boolean flag = true;

            for (int j = 0; j < n; j++)
                if (arr[j] > arr[i])
                    flag = false;

            if (flag == true)
                return arr[i];
        }

        // this line will never be reached. This line is written so the compiler doesn't
        // give warnings about return statement
        return -1;
    }

    public static void main(String[] args) {
        int arr[] = { 5, 8, 20, 10 };

        System.out.println(getLargest(arr));
    }
}
