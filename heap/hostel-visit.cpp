#include <iostream>
#include <queue>
using namespace std;
#define ll long long
long dist(ll x, ll y)
{
    return x * x + y * y;
}
int main()
{
    ll n, k, type, x, y;
    cin >> n >> k;
    priority_queue<ll> pq;
    while (n--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> x >> y;
            ll temp = dist(x, y);
            if (k)
            {
                pq.push(temp);
                k--;
            }
            else
            {
                ll top = pq.top();
                if (top > temp)
                {
                    pq.pop();
                    pq.push(temp);
                }
            }
        }
        else
        {
            // if(!pq.empty()){
            cout << pq.top() << endl;
            // }
        }
    }
    return 0;
}