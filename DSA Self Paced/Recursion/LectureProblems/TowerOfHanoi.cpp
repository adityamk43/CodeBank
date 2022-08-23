#include <bits/stdc++.h>

using namespace std;

void TOH(int n, char A, char B, char C)
{
    if (n==1)
    {
        cout << "Move 1 from Disk " << A << " to " << C << endl;
        return;
    }
    
    TOH(n-1, A, C, B);
    cout << "Move " << n << " from Disk " << A << " to " << C << endl; 
    TOH(n-1, B, A, C);
}

int main()
{
    TOH(3, 'A', 'B', 'C');
    return 0;
}