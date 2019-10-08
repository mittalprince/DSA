#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        // ll temp = INT_MAX;
        ll ct = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            // if(arr[i] < temp){
            //     ct++;
            //     temp = arr[i];
            // }
        }
        if (n > 5)
        {
            ll temp = INT_MAX;
            for (ll i = 0; i < 5; i++)
            {
                if (arr[i] < temp)
                {
                    ct++;
                    temp = arr[i];
                }
            }
            for (ll i = 0; i < n - 5; i++)
            {
                ll mi = INT_MAX;
                for (ll j = i; j < i + 5; j++)
                {
                    if (mi > arr[j])
                    {
                        mi = arr[j];
                        // ct++;
                    }
                }
                // cout<<mi<<" "<<arr[i+5]<<endl;
                if (mi > arr[i + 5])
                {
                    // cout<<"yes";
                    ct++;
                }
            }
        }
        else
        {
            ct = 1;
            ll mi = arr[0];
            for (ll i = 1; i < n - 1; i++)
            {
                if (mi > arr[i])
                {
                    mi = arr[i];
                    ct++;
                }
                // if(mi > arr[i+1]){
                //     ct++;
                // }
            }
            if (mi > arr[n - 1])
            {
                ct++;
            }
        }
        cout << ct << endl;
    }
    return 0;
}

//October Challenege