#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(ll arr[], ll s, ll e, ll n)
{
    ll mid = (s + e) / 2;
    ll i = s, k = s, j = mid + 1;
    ll temp[n];
    ll count = 0;
    while (i <= mid && j <= e)
    {

        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }

        if (arr[i] > arr[j])
        {   count += mid-i+1;
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= e)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (ll i = s; i <= e; i++)
    {
        arr[i] = temp[i];
    }

    return count;
}

ll mergeSort(ll arr[], ll s, ll e, ll n)
{

    if (s >= e)
    {
        return 0;
    }
    ll mid = (s + e) / 2;

    ll x = mergeSort(arr, s, mid, n);
    ll y =mergeSort(arr, mid + 1, e, n);

    return x+y+merge(arr, s, e, n);
    // return;
}
int main()
{

    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<mergeSort(arr, 0, n - 1, n)<<endl;
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    return 0;
}