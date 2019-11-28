#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> m;

    void addEdge(int u, int v)
    {
        m[u].push_back(v);
    }

    void DFS(int s, unordered_map<int, bool> &visited)
    {
        visited[s] = true;

        for (auto i : m[s])
        {
            if (!visited[i])
            {
                DFS(i, visited);
            }
        }
    }

    bool dfs(int s, int d)
    {
        // cout<<s<<endl<<d<<endl<<endl;
        unordered_map<int, bool> visited;
        visited[d] = false;

        DFS(s, visited);
        // for(auto i: visited){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        if (visited[d])
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int temp;
        cin >> temp;
    }

    int e;
    cin >> e;
    graph g;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }

    int s, d;
    cin >> s >> d;
    cout << g.dfs(s, d);
}