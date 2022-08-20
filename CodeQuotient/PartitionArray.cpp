#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

void partitionArray(int arr[], int n, int x)
{
  int i, j, temp;
  i = 0;
  j = n-1;
  
  while (i < j)
  {
    while (arr[i] <=x && i<j)
       i++;
    while (arr[j] > x && i<j)
       j--;
    
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
	
    i++;
    j--;
  }  
}
int main()
{
    int i, n, x;
    cin>>n>>x;
    
    int arr[n];
    for(i = 0; i < n; i++) 
        cin>>arr[i];
    
    partitionArray(arr, n, x);
    
   for (i = 0; i < n; i++) 
       cout<<arr[i]<<endl;
  
    return 0;
}