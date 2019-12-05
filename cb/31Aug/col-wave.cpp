#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ColWav(vector< vector<ll> >v, ll m, ll n){
    ll i, k=0, l=0;

    while(l<n){
        for(i=k; i<m; i++){
            cout<<v[i][l]<<", ";
        }
        l++;
        if(l<n){
            for (i = m - 1; i >= k; i--)
            {
                cout << v[i][l] << ", ";
            }
            l++;
        }
    }
}

int main()
{
    ll m, n;
    cin >> m >> n;
    vector<vector<ll>> v(m, vector<ll>(n));

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    ColWav(v, m, n);
    cout << "END" << endl;
    return 0;
}
