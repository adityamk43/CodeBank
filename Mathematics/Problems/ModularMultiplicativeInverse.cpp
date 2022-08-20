/*
Given two integers ‘a’ and ‘m’. The task is to find the smallest modular multiplicative inverse of ‘a’ under modulo ‘m’.

 

Example 1:

Input:
a = 3
m = 11
Output: 4
Explanation: Since (4*3) mod 11 = 1, 4 
is modulo inverse of 3. One might think,
15 also as a valid output as "(15*3)
mod 11"  is also 1, but 15 is not in 
ring {0, 1, 2, ... 10}, so not valid.
 

Example 2:

Input:
a = 10
m = 17
Output: 12
Explanation: Since (12*10) mod 17 = 1,
12 is the modulo inverse of 10.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function function modInverse() that takes a and m as input parameters and returns modular multiplicative inverse of ‘a’ under modulo ‘m’. If the modular multiplicative inverse doesn't exist return -1.

 

Expected Time Complexity : O(m)
Expected Auxilliary Space : O(1)

 

Constraints:
1 <= a <= 104
1 <= m <= 104
*/

//@AUTHOR: ADITYA BHARDWAJ
//@CREATED: 16 JUNE 2022

// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

//PROBLEM WAS I USED A FERMAT'S LITTLE THEOREM WHICH FINDS MODULO INVERSE ONLY WHEN M IS PRIME THAT'S WHY MY ACCURACY WAS 50%

class Solution{
    public:
    //Complete this function
    int modInverse(int a, int m)
    {
        //Your code here
        
        for (int i=0; i<m; i++)
        {
            if (((a%m)*(i%m))%m == 1)
                return i;
            
        }
        
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends


/*USING FERMAT'S LITTLE THEOREM WHICH FINDS MODULO INVERSE ONLY WHEN M IS PRIME

// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

#include <cmath>

class Solution{
    public:
    
    // To compute x^y under modulo m
    int power(int x, unsigned int y, unsigned int m)
    {
        if (y == 0)
            return 1;
        int p = power(x, y / 2, m) % m;
        p = (p * p) % m;
     
        return (y % 2 == 0) ? p : (x * p) % m;
    }
     
    // Function to return gcd of a and b
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    
    // Function to find modular inverse of a under modulo m
    // Assumption: m is prime
    int modInverse(int a, int m)
    {
        //your code here
        
        int g = gcd(a, m);
        if (g != 1)
            return -1;
        else
        {
            // If a and m are relatively prime, then modulo
            // inverse is a^(m-2) mode m
            return power(a, m - 2, m);
        }
    }
    
};

// { Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends
*/