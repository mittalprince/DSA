#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canCut(ll trees[], ll n, ll m, ll height)
{

    ll cut_tree = 0;
    for (ll i = 0; i < n; i++)
    {
        if (trees[i] > height)
        {
            cut_tree += (trees[i] - height);
            if (cut_tree >= m)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    ll n, m;
    cin >> n >> m;
    ll trees[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> trees[i];
    }

    sort(trees, trees + n);
    ll s = trees[0];
    ll e = trees[n - 1];
    ll mid, ans = 0;
    while (s <= e)
    {
        mid = (s + e) >> 1;
        if (canCut(trees, n, m, mid))
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

    return 0;
}