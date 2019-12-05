#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canPlace(ll dist[], ll n, ll c, ll min_dist)
{
    int cow = 1;
    int curr_stall = dist[0];
    for (ll i = 1; i < n; i++)
    {
        ll x = dist[i];
        if ((x - curr_stall) >= min_dist)
        {
            cow++;
            curr_stall = x;
            if (cow == c)
            {
                return true;
            }
        }
    }

    return false;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        ll dist[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> dist[i];
        }
        sort(dist, dist + n);

        ll s = dist[0];
        ll e = dist[n - 1] - dist[0];
        int mid, ans = 0;
        while (s <= e)
        {
            mid = (s + e) >> 1;
            if (canPlace(dist, n, c, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}