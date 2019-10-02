#include <iostream>
using namespace std;
typedef long long ll;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        ll temp = n / k;
        if (temp % k == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}