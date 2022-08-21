/**
 * @file StringPalindromRecursion.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 8:07PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

import java.util.Scanner;

class StringPalindromRecursion {

    public static boolean isPalindrome(String str, int start, int end) {
        if (start >= end)
            return true;

        return (str.charAt(start) == str.charAt(end)) && isPalindrome(str, start + 1, end - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();
        sc.close();

        if (isPalindrome(str, 0, str.length()-1))
            System.out.println("Yes\n");
            else
            System.out.println("No\n");

    }
}