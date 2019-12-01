#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define N 26

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> c(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
    return c;
}

vector<vector<ll>> pow(vector<vector<ll>> a, ll n)
{
    if (n == 1)
        return a;
    if (n & 1)
        return mul(a, pow(a, n - 1));
    else
    {
        vector<vector<ll>> temp = pow(a, (n >> 1));
        return mul(temp, temp);
    }
}

int main()
{
    int n;
    cin >> n;
    bool n_1 = false;
    if (n == 1)
    {
        n_1 = true;
    }
    vector<vector<ll>> arr(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char ch;
            cin >> ch;
            arr[i][j] = ch - '0';
        }
    }

    vector<vector<ll>> transpose(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            transpose[i][j] = arr[i][j];
        }
    }

    if (!n_1)
    {
        vector<vector<ll>> c = pow(arr, n - 1);
        ll ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ans = (ans + c[i][j]) % mod;
            }
        }

        cout << ans << "\n";
    }
    else
    {
        cout << "26"
             << "\n";
    }
    return 0;
}