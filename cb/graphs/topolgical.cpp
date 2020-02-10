#include <iostream>
#include <map>
#include <list>
#include <queue>
#include<unordered_map>
#include<string>
using namespace std;

template <typename T>
class graph
{
    unordered_map<T, list<T>> m;
    unordered_map<T, int> degree;

public:
    graph()
    {
    }

    void addEdge(T u, T v, bool bidir = false)
    {
        m[u].push_back(v);
        if (bidir)
        {
            m[v].push_back(u);
        }
    }

    void inDegree(){
        for (auto node : m)
        {
            degree[node.first] = 0;
        }

        for(auto node: m){
            for(auto v: node.second){
                degree[v]++;
            }
        }
    }

    void topological(){

        queue<T> q;

        for(auto deg: m){
            T node = deg.first;
            if(degree[node] == 0){
                q.push(node);
            }
        }

        while(!q.empty()){
            T temp = q.front();
            cout<<temp<<" ";
            q.pop();

            for(auto i: m[temp]){
                degree[i]--;
                if(degree[i] == 0){
                    q.push(i);
                }
            }
        }

        cout<<endl;

    }
};

int main()
{

    graph<string> g;
    g.addEdge("english", "plbasic");
    g.addEdge("plbasic", "c++");
    g.addEdge("c++", "algoo++");
    g.addEdge("math", "c++");
    g.addEdge("math", "algo++");
    g.addEdge("algo++", "dp");
    g.addEdge("algo++", "ml");
    g.addEdge("algo++", "data-science");
    g.addEdge("ml", "data-scinece");

    g.inDegree();
    g.topological();
}