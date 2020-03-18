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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int temp, prev, idx;
        bool zero = false, flag = false, third = false;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            b[i] = temp - a[i];
            if (b[i] == 0)
                continue;
            else if (!flag || (prev == b[i] && idx == i - 1))
            {
                prev = b[i];
                flag = true;
                idx = i;
            }
            else
            {
                third = true;
            }
        }

        if (third || (flag && prev < 0))
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}