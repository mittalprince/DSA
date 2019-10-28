#include <bits/stdc++.h>

using namespace std;

#define ll long long

class check
{
public:
    ll val;
    ll pos;
};

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;

        int p;
        cin >> n >> k >> p;
        ll a[n];

        check bda;
        check chota;

        cin >> a[0];
        bda.val = a[0];
        bda.pos = 0;
        chota.val = a[0];
        chota.pos = 0;
        for (ll i = 1; i < n; i++)
        {
            cin >> a[i];
            if (bda.val < a[i])
            {
                bda.val = a[i];
                bda.pos = i;
            }

            if (chota.val > a[i])
            {
                chota.val = a[i];
                chota.pos = i;
            }
        }
        int end;
        if (k & 1)
        {
            end = p;
        }
        else
        {
            if (p == 0)
            {
                end = 1;
            }
            else
            {
                end = 0;
            }
        }

        if (p == end)
        {
            if (p == 0)
            {
                cout << bda.val << endl;
            }
            else
            {
                cout << chota.val << endl;
            }
        }
        else
        {
            if (p == 0)
            {
                if (bda.pos - 1 >= 0 && bda.pos + 1 <= n - 1)
                {
                    ll ans = min(a[bda.pos - 1], a[bda.pos + 1]);
                    cout << ans << endl;
                }
            }
            else
            {
                if (chota.pos - 1 >= 0 && chota.pos + 1 <= n - 1)
                {
                    ll ans = max(a[chota.pos - 1], a[chota.pos + 1]);
                    cout << ans << endl;
                }
            }
        }
    }
}