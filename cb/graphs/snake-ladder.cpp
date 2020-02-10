#include <iostream>
#include <map>
#include <list>
#include <queue>
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
        map<T, bool> visited;
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
    int board[36] = {0};

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;

    for(int u=0; u<=36; u++){
        for(int dice = 1; dice<=6; dice++){
            int v = dice+u;
            v += board[v];
            if(v <= 36){
                g.addEdge(u, v, false);
            }
        }
    }
    g.sssp(1, 36);
}