#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template <typename T>
class graph
{
    map<T, list<T>> m;

public:
    graph()
    {
    }

    void addEdge(T u, T v, bool bidir = true)
    {
        m[u].push_back(v);
        if (bidir)
        {
            m[v].push_back(u);
        }
    }

    // using bfs
    void sssp(T src, T dest)
    {

        queue<T> q;
        map<T, int> dist;
        map<T, int> parent;

        for (auto i : m)
        {
            dist[i.first] = INT_MAX;
        }

        dist[src] = 0;
        parent[src] = src;
        q.push(src);

        while (!q.empty())
        {
            T temp = q.front();
            cout << temp << " ";
            q.pop();

            for (auto i : m[temp])
            {
                if (dist[i] == INT_MAX)
                {
                    dist[i] = dist[temp] + 1;
                    parent[i] = temp;
                    q.push(i);
                }
            }
        }

        cout << endl;
        T temp = dest;
        while (temp != src)
        {
            cout << temp << " ";
            temp = parent[temp];
        }

        cout << endl
             << "Soruce Node " << src << endl;

        for (auto i : dist)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
};

int main()
{

    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(5, 7);
    g.addEdge(7, 8);

    g.sssp(0, 8);
}