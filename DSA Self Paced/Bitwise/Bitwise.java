/**
 * @file Bitwise.java
 * @author Aditya Bhardwaj
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
public class Bitwise {
    public static void main(String[] args) {
        
        int x = 3, y=2;
        int z = -13;
        
        System.out.println(x & y);
        System.out.println(x | y);
        System.out.println(x ^ y);
        System.out.println(x << y);
        System.out.println(z >> y);
        System.out.println(z >>> y);
        System.out.println(~x);
    }
}
