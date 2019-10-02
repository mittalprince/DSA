#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    set<ll> s;
    unordered_map<ll, vector<ll>> m;
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        s.insert(temp);
        m[temp].push_back(i + 1);
    }

    ll ct = 0;
    ll ans = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        ll j = m[*it].size();
        while (j--)
        {
            ans += (*it) * ct + 1;
            ct++;
        }
    }
    cout << ans << endl;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        for (ll j = 0; j < m[*it].size(); j++)
        {
            cout << m[*it][j] << " ";
        }
    }
    cout << endl;
    return 0;
}