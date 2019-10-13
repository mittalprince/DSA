#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q, m;
        cin >> n >> m >> q;
        vector<ll> r(n, 0);
        vector<ll> c(m, 0);

        while (q--)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            r[x]++;
            c[y]++;
        }
        ll ct = 0;
        ll even_row = 0;
        ll odd_row = 0;
        ll even_col = 0;
        ll odd_col = 0;
        for (ll it = 0; it < n; it++)
        {
            if (r[it] & 1)
            {
                odd_row++;
            }
            else
            {
                even_row++;
            }
        }
        for (ll it = 0; it < m; it++)
        {
            if (c[it] & 1)
            {
                odd_col++;
            }
            else
            {
                even_col++;
            }
        }
        cout << (odd_col * even_row) + (even_col * odd_row) << endl;
    }
    return 0;
}