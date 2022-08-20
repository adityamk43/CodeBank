/* add c++ headers if necessary*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<limits.h>
// Include headers as needed

using namespace std;

int SecondMax(int arr[], int n)
{
  int max = INT_MIN, secondmax = INT_MIN;
  
  for (int i=0; i<n; i++)
    if (arr[i] > max)
      max = arr[i];
  
  for (int i=0; i<n; i++)
	if (arr[i] > secondmax && arr[i] < max)
      secondmax = arr[i];
  
  if (secondmax!=INT_MIN)
    return secondmax;
  else
    return 0;
 }

int main()
{
    // Write your code here
  int n;	
  cin >> n;
  int arr[n];
  
  for (int i=0; i<n; i++) 
    cin >> arr[i];
  
  
  cout << SecondMax(arr, n);
	
    return 0;
}


/* add tail for c++ if necessary*/