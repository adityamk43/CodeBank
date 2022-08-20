#include<bits/stdc++.h>
using namespace std;

int countVowelSubstr(string str) {
  // Write your code here
  int count = 0;
  int n = str.length();
  for (int i = 0; i < n; i++)
  {
  	if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||str[i] == 'E' ||str[i] == 'I' ||str[i] == 'O' ||str[i] == 'U')
    { 
      count = (count + (n-i)%10007)%10007;
    }
  }
  
  return count;
  
}

int main(){
  string str;
  cin>>str;
  cout<< countVowelSubstr(str);
  return 0;
}