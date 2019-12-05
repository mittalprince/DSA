#include <iostream>

using namespace std;
typedef long long ll;

bool isPalindrome(ll arr[], ll s, ll e)
{
    if (s == e || s > e)
    {
        return true;
    }

    if (arr[s] != arr[e])
    {
        return false;
    }
    return isPalindrome(arr, s + 1, e - 1);
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
    if (isPalindrome(arr, 0, n - 1))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}