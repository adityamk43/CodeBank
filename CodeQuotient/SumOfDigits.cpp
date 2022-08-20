/* add c++ headers if necessary*/

#include<iostream>
#include<cstdio>
#include<cmath>
// Include headers as needed

using namespace std;

//Iterative Solution
int SumofDigits(int n)
{
  int rem = 0, temp = n;
  int sum = 0;
  
  while(temp!=0)
  {
    rem = temp%10;
  	sum = sum + rem;
    temp = temp/10;
  }
  
  return sum;
}

//Recursive Solution
int sumofDigits(int n)
{
  if (n == 0)
    return n;
  
  return n%10 + sumofDigits(n/10);
}


int main()
{
    // Write your code here
	int n, T;
  	cin >> T;
  
  	while(T>0)
    {
      cin >> n;
      cout << sumofDigits(n) << endl;
      T--;
    }
  
    // Return 0 to indicate normal termination
    return 0;
}

/* add tail for c++ if necessary*/