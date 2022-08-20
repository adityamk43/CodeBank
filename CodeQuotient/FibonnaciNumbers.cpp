/* add c++ headers if necessary*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void fib(int i, int a, int b, int n)
{
  if (i > n)
    return;

  int c = a + b;

  fib(i + 1, b, c, n);

  cout << c << endl;
}

int main()
{
  int n;
  cin >> n;
  int a = 0, b = 1;

  fib(3, 0, 1, n);

  if (n >= 2)
    cout << b << endl;
  if (n >= 1)
    cout << a << endl;

  return 0;
}
/* add tail for c++ if necessary*/