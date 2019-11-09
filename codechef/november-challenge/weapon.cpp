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
        int arr[10] = {0};
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int i = 0; i < 10; i++)
            {
                if (s[i] == '1')
                {
                    arr[i]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] & 1)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}