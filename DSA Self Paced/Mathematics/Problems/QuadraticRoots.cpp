/*
Given a quadratic equation in the form ax2 + bx + c. Find its roots.

Note: Return the maximum root followed by the minimum root.

Example 1:

Input:
a = 1
b = -2
c = 1
Output: 1 1
Explanation:
Roots of equation x2-2x+1 are 1 and 1.

Example 2:

Input:
a = 1
b = -7
c = 12
Output: 4 3
Explanation: Roots of equation 
x2 - 7x + 12 are 4 and 3.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function quadraticRoots() which takes a, b, c as input parameters and returns a list of two integers containing the floor value of its roots in decreasing order. If roots are imaginary, the returning list should contain only 1 integer ie -1. Always return the greatest integer smaller than or equal to the result.
Note: If roots are imaginary, the generated output will display "Imaginary".

 

Expected Time Complexity: O(1)
Expected Auxiliary Space : O(1)

 

Constraints:
-103 <= a,b,c <= 103
*/


/*
    OPTIMIZED SOLUTION FOR MY CODE FOR MAX AND MIN ROOTS ORDERING
    
    vector<int> roots;
       double d= (b*b) - (4*a*c);
       if(d<0)
       roots.push_back(-1);
       else{
           double x1,x2;
           x1=(-b+sqrt(d))/(2*a);
           x2=(-b-sqrt(d))/(2*a);
       roots.push_back(floor(max(x1,x2)));
       roots.push_back(floor(min(x1,x2)));
       }
       return roots;


//@AUTHOR: ADITYA BHARDWAJ
//@CREATED: 16 JUNE 2022
*/
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#include <cmath> 

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
        
        double D;
        vector<int> roots;
        
        
        D = floor((b*b)-4*a*c);
        
        if (D>0 || D==0)
        {
            double r1 = floor((-b + sqrt(D))/(2*a));
            double r2 = floor((-b - sqrt(D))/(2*a));
            
            //my mistake for attempt 2 is i didn't ordered the max and min roots before but below i did in 2nd attempt
            if (r1 > r2)
            {
                roots.push_back(r1);
                roots.push_back(r2);
            }
            else{
                roots.push_back(r2);
                roots.push_back(r1);
            }
        }
        else
        {
            roots.push_back(-1);
        }
        
        return roots;
        
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends