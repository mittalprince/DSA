#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(ll Arr[], ll s, ll e)
{
    ll mid = (s + e) / 2;
    ll arr[e + 1];
    ll i = s, k = s, j = mid + 1;
    while (i <= mid && j <= e)
    {
        if (Arr[i] < Arr[j])
        {
            arr[k] = Arr[i];
            i++;
        }
        else
        {
            arr[k] = Arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        arr[k] = Arr[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        arr[k] = Arr[j];
        k++;
        j++;
    }

    for (ll i = s; i <= e; i++)
    {
        Arr[i] = arr[i];
    }
}
void mergeSort(ll arr[], ll s, ll e)
{
    if (s >= e)
    {
        return;
    }
    ll mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    return merge(arr, s, e);
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
    mergeSort(arr, 0, n - 1);
    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}