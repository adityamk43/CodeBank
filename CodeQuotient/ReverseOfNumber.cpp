/* add c++ headers if necessary*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int ReverseofNumber(int n)
{
  int rev = 0, rem = 0;
  int temp = n;
  
  while(temp!=0)
  {
    rem = temp%10;
    rev = rev*10 + rem;
    temp = temp/10;
  }
  
  return rev;
}

int reverseofNumber(int n, int res)
{
  if (n == 0)
    return res;
  
  int rem = n%10;
  res = res*10 + rem;
  
  return reverseofNumber(n/10, res);
}

int main()
{
	int n;
    
  	cin >> n;
    cout << reverseofNumber(n, 0) << endl;
     
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
/* add tail for c++ if necessary*/