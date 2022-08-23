#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    vector<string> y = {"1", "2", "15", "-7","300" };

    sort(y.begin(), y.end());

    for (int i=0; i< y.size(); i++)
    {
        cout << y[i];
    }
    return 0;
}