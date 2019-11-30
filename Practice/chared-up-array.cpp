#include <bits/stdc++.h>
using namespace std;
#define m 1000000007

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n >= 64)
        {
            cout << "0" << endl;
        }
        else
        {
            long long ans = 0;
            long long val = (1ll << (n - 1));
            for (int i = 0; i < n; i++)
            {
                if (arr[i] >= val)
                {
                    ans = (ans + arr[i] % m) % m;
                }
            }
            cout << ans << endl;
        }
    }
}

//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/charged-up-array-f35a5e23/description/