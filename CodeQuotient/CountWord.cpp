#include <bits/stdc++.h>
using namespace std;

int countWords(char str[])
{
    int count = 0;
    int inWord = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            inWord = 0;
        else if (inWord == 0)
        {
            count++;
            inWord = 1;
        }
    }
    return count;
}

int main()
{
    char str[100] = "\0";
    int num;
    scanf("%[^\n]", str);
    num = countWords(str);
    cout << num;
    return 0;
}