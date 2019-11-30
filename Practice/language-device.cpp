// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define M 1000000007

// class graph
// {
// public:
//     map<int, list<int>> m;

//     void addEdge(int u, int v)
//     {
//         m[u].push_back(v);
//     }

//     int chudaap(int n, int N)
//     {
//         unordered_map<int, bool> visisted;
//         visisted[n] = true;
//         queue<int> q;
//         q.push(n);
//         int ct = 1;

//         while (!q.empty())
//         {
//             int temp = q.front();
//             q.pop();

//             for (auto i : m[temp])
//             {
//                 if (!visisted[i])
//                 {
//                     q.push(i);
//                 }
//                 ct++;
//                 if (ct >= N)
//                 {
//                     return 1;
//                 }
//             }
//         }
//         if (ct >= N)
//         {
//             return 1;
//         }
//         return 0;
//     }

//     int cal(vector<int> v, int N)
//     {
//         int ans = 0;
//         for (int i = 0; i < v.size(); i++)
//         {
//             ans += m[v[i]].size();
//         }

//         for (auto i : m)
//         {
//             ans += chudaap(i.first, N);
//         }
//         return ans;
//     }
// };

// int main()
// {
//     int n;
//     cin >> n;
//     ll ct = 0;
//     graph g;
//     vector<int> v;
//     for (int i = 0; i < 26; i++)
//     {
//         for (int j = 0; j < 26; j++)
//         {
//             char ch;
//             cin >> ch;
//             if (ch == '1')
//             {
//                 ct++;
//                 g.addEdge(j, i);
//                 if (i == j)
//                 {
//                     v.push_back(i);
//                 }
//             }
//         }
//     }

//     if (n == 1)
//     {
//         cout << "26" << endl;
//     }
//     else if (n == 2)
//     {
//         cout << ct << endl;
//     }
//     else
//     {
//         cout << (g.cal(v, n) % M) << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 26
typedef long long ll;

void multiply(ll a[][N], ll b[][N], ll res[][N])
{
    ll mul[N][N];
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            mul[i][j] = 0;
            for (ll k = 0; k < N; k++)
                mul[i][j] += a[i][k] * b[k][j];
        }
    }
    for (ll i = 0; i < N; i++)
        for (ll j = 0; j < N; j++)
            res[i][j] = mul[i][j];
}

void power(ll G[N][N], ll res[N][N], ll n)
{
    if (n == 1)
    {
        for (ll i = 0; i < N; i++)
            for (ll j = 0; j < N; j++)
                res[i][j] = G[i][j];
        return;
    }

    power(G, res, n / 2);
    multiply(G, G, res);
    if (n % 2 != 0)
        multiply(res, G, res);
}

int main()
{
    ll n;
    cin >> n;
    n--;
    ll arr[N][N], res[N][N], b[N][N];
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            b[i][j] = arr[j][i];
        }
    }
    power(b, res, n);
    ll ans = 0;

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //       cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //       cout<<b[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl<<endl;
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            ans += res[i][j];
        }
    }

    cout << (ans % mod) << endl;
}