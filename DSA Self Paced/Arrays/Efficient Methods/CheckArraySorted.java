import java.util.ArrayList;

/**
 * @file CheckArraySorted.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-01 07:17PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

class CheckArraySorted{

    static boolean isSorted(ArrayList<Integer> arr)
    {
        for (int i=1; i< arr.size(); i++)
            if (arr.get(i) < arr.get(i-1))
                return false;
        
        return true;
    }

    public static void main(String[] args) {

        ArrayList<Integer> arr = new ArrayList<Integer>();
        // arr.add(8);
        // arr.add(12);
        // arr.add(15);

        arr.add(100);
        arr.add(20);
        arr.add(200);

        
        System.out.println(isSorted(arr));
    }
}