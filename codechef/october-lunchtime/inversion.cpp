#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(ll n)
{
    ll ans = n * (n + 1);
    return ans >> 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        ll ans = 0;
        ll t1 = sum(k);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ll temp = 0;
                if (arr[i] > arr[j])
                {
                    temp++;
                }
                ans += temp * t1;
                // cout<<arr[i]<<" "<<temp<<" "<<ans<<endl;
            }
        }
        ll t2 = sum(k - 1);
        // cout<<t2<<" ************** "<<endl;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                ll temp = 0;
                if (arr[i] > arr[j])
                {
                    temp++;
                }
                ans += temp * t2;
                // cout<<arr[i]<<" "<<arr[j]<<" "<<temp<<" "<<ans<<endl;
            }
        }

        cout << ans << endl;
    }
    return 0;
}