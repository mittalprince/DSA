#include <iostream>
using namespace std;
typedef long long ll;

ll pow(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }

    ll k = pow(a, b / 2);
    if (b & 1)
    {
        return a * k * k;
    }
    else
    {
        return k * k;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a, b, c, d, e, s, temp;
        cin >> a;
        temp = pow(10, n);
        s = (temp << 1) + a;
        cout << s << "\n";
        cin >> b;
        c = temp - b;
        cout << c << "\n";
        cin >> d;
        e = temp - d;
        cout << e << "\n";
        int ans;
        cin >> ans;
        if (ans == -1)
        {
            break;
        }
    }
}