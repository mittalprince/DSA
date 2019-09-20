#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll log(ll n)
{
    ll ct = 0;
    while (n)
    {
        n = n >> 1;
        ct++;
    }
    return ct - 1;
}

int main()
{

    ll t;
    cin >> t;

    int fs[] = {2, 3, 0, 9};
    while (t--)
    {
        ll n;
        cin >> n;
        ll max_pow = log(n);
        if (n == 1)
        {
            cout << "0" << endl;
        }
        else if (n == 2 || n == 3)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << fs[(max_pow - 2) % 4] << endl;
        }
    }
    return 0;
}