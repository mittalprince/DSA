#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool search(vector<vector<ll>> v, ll n, ll m, ll key)
{
    if (n == 0 || m == 0)
    {
        return false;
    }
    if (key < v[0][0] || key > v[n - 1][m - 1])
    {
        return false;
    }

    ll i, k = 0, l = 0;
    bool ans = false;
    while (k < n && l < m)
    {
        if (v[k][m - 1] == key)
        {
            ans = true;
            break;
        }
        if (key < v[k][m - 1])
        {
            m--;
        }
        else if (key > v[k][m - 1])
        {
            k++;
        }
    }

    return ans;
}

int main()
{

    ll n, m, key;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    cin >> key;
    cout << search(v, n, m, key) << endl;
    return 0;
}