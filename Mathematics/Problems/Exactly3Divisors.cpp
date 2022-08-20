/*
Given a positive integer value N. The task is to find how many numbers less than or equal to N have numbers of divisors exactly equal to 3.

 

Example 1:

Input:
N = 6
Output: 1
Explanation: The only number less than 6 with 
3 divisors is 4.
Example 2:

Input:
N = 10
Output: 2
Explanation: 4 and 9 have 3 divisors.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function exactly3Divisors() that takes N as input parameter and returns count of numbers less than or equal to N with exactly 3 divisors.

 

Expected Time Complexity : O(N1/2 * N1/4)
Expected Auxilliary Space :  O(1)

 

Constraints :
1 <= N <= 109
*/
//@AUTHOR: ADITYA BHARDWAJ
//@CREATED: 16 JUNE 2022

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    bool isPrime(int N)
    {
        //Your code here
        
        
        if (N==2 || N==3)
            return true;
            
        if (N==1 || N%2 == 0 || N%3 == 0)
            return false;
            
        for (int i = 5; i*i <= N; i=i+6)
        {
            if (N%i == 0 || (N%(i+2)) == 0)
                return false;
        }
        
        return true;
    }
    
    int exactly3Divisors(int N)
    {
        //Your code here
        int count = 0;
        
        for (int i = 0; i*i <=N; i++)
        {
            if(isPrime(i))
            {
                count++;
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.


int main()
 {
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
}  // } Driver Code Ends