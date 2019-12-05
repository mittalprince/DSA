#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r, y, temp = 0;
        bool flag = false;
        cin >> l >> r >> y;
        ll min = LLONG_MAX;
        ll max = LLONG_MIN;
        unordered_map<ll, int> m;
        for (ll i = l - 1; i < r; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
            if (max < arr[i])
            {
                max = arr[i];
            }
            m[arr[i]]++;
        }
        // cout<<min<<" "<<max<<endl;
        for (ll i = min; i <= max; i++)
        {
            if (m[i])
            {
                if (temp < y)
                {
                    temp += i;
                }

                if (temp >= y)
                {
                    cout << temp << endl;
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}