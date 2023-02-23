#include <iostream>
#include <string>
using namespace std;

int maxIntVal(string value, int n)
{
    int res = value[0] - '0';

    for (int i = 1; i < n; i++)
    {
        res = max(res, max(res + (value[i] - '0'), res * (value[i] - '0')));
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