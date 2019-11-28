#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

class graph
{
public:
    unordered_map<int, list<p>> m;

    void addEdge(int u, int v, int w)
    {
        m[u].push_back(make_pair(v, w));
    }

    int sp(int s, int d, int arr[], int n)
    {
        priority_queue<p, vector<p>, greater<p>> q;
        unordered_map<int, int> dist;

        for (int i = 0; i < n; i++)
        {
            dist[arr[i]] = INT_MAX;
        }

        q.push(make_pair(0, s));
        dist[s] = 0;
        while (!q.empty())
        {
            int u = q.top().second;
            q.pop();

            for (auto i : m[u])
            {
                int node = i.first;
                int wt = i.second;

                if (dist[node] > dist[u] + wt)
                {
                    dist[node] = dist[u] + wt;
                    q.push(make_pair(dist[node], node));
                }
            }
        }
        return dist[d];
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int e;
    cin >> e;
    graph g;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }

    int s, d;
    cin >> s >> d;
    cout << g.sp(s, d, arr, n);
}