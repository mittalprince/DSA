#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        int flag = true;
        int x = n >> 2;
        int y = (n << 1) >> 2;
        int z = (n * 3) >> 2;

        if (arr[x] <= arr[x - 1] || arr[y] <= arr[y - 1] || arr[z] <= arr[z - 1])
        {
            flag = false;
        }

        if (!flag)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << arr[x] << " " << arr[y] << " " << arr[z] << endl;
        }
    }
    return 0;
}