#include <iostream>
#include <string>
using namespace std;

long long int maxIntVal(string value, int n)
{
    long long int res = value[0] - '0';

    for (int i = 1; i < n; i++)
    {
        res = max(res + (value[i] - '0'), res * (value[i] - '0'));
    }

    return res;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string value;
        cin >> value;

        cout << maxIntVal(value, value.length()) << endl;
    }

    return 0;
}