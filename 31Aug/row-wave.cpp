#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void RowWave(vector<vector<ll>> v, ll m, ll n)
{
    ll i, k = 0, l = 0;

    while (k < m)
    {
        for (i = l; i < n; i++)
        {
            cout << v[k][i] << ", ";
        }
        k++;
        if (k < m)
        {
            for (i = n - 1; i >= l; i--)
            {
                cout << v[k][i] << ", ";
            }
            k++;
        }
    }
}

int main()
{
    ll m, n;
    cin >> m >> n;
    vector<vector<ll>> v(m, vector<ll>(n));

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    RowWave(v, m, n);
    cout << "END" << endl;
    return 0;
}
