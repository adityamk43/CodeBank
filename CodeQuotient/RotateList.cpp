#include <iostream>
#include <cstdio>
#include <cmath>
// Include headers as needed

using namespace std;

void RotateList(int arr[], int n, int r)
{
    int temp[n];

    for (int i = 0; i < n; i++)
        temp[i] = arr[(i + r) % n];

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << temp[i];
    }
}

int main()
{
    // Write your code here
    int T, n, r;

    cin >> T;

    while (T > 0)
    {
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cin >> r;

        RotateList(arr, n, r);

        cout << endl;

        T--;
    }
    // Return 0 to indicate normal termination
    return 0;
}

// #include<iostream>
// #include<cstdio>
// #include<cmath>
// // Include headers as needed

// using namespace std;

// void RotateList(int arr[], int n, int r)
// {
//   int temp1, temp2;

//   for (int k=0; k<=r; k++){
//     temp1 = arr[n-1];
//     for (int i=0; i<n; i++)
//     {
//         temp2 = arr[i];
//         arr[i] = temp1;
//         temp1 =temp2;
//     }
//   }

//   for (int i=0; i<n; i++)
//     	cout << arr[i] << " ";
// }

// int main()
// {
//     // Write your code here
// 	int T,n, r;

//   	cin >> T;

//   	while(T>0)
//     {
//       cin >> n;
//       int arr[n];

//       for (int i=0; i<n; i++)
//     	cin >> arr[i];

//       cin >> r;

//       RotateList(arr, n, r);

//       cout << endl;

//     }
//     // Return 0 to indicate normal termination
//     return 0;
// }