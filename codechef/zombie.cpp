#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll r[n + 1];
        ll h[n + 1];
        ll c[n + 1] = {0};
        r[0] = 0;
        h[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> r[i];
            ll p = i - r[i];
            if (p < 1)
            {
                p = 1;
            }
            ll q = i + r[i];
            if (q > n)
            {
                q = n;
            }

            c[p] += 1;
            c[q + 1] += -1;
        }

        for (ll i = 2; i <= n; i++)
        {
            c[i] += c[i - 1];
        }

        sort(c, c + n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        sort(h, h + n + 1);
        bool flag = true;
        for (ll i = 1; i <= n; i++)
        {
            if (c[i] != h[i])
            {
                flag = false;
            }
        }
        if (flag)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }
    return 0;
}