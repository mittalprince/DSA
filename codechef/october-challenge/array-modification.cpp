#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll temp = n * 3;
        if (n & 1)
        {
            ll div = k / temp;
            if (div)
            {
                arr[n >> 1] = 0;
            }
        }
        ll index = k % temp;
        for (ll i = 0; i < index; i++)
        {
            ll a = i % n;
            ll b = n - a - 1;
            // cout<<a<<" "<<b<<endl;
            arr[a] = arr[a] ^ arr[b];
        }

        for (ll i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}