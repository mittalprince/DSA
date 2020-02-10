#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
using namespace std;

template<typename T>
class graph{
    map<T, list<T> > adj;
    map<T, int> deg;

    public:
        graph(int n){
            for (T i = 1; i <=n; i++)
            {
                deg[i] = 0;
            }
        }
        void addEdge(T u, T v, bool bidir=false){
            adj[u].push_back(v);
            deg[v]++;

            if(bidir){
                adj[v].push_back(u);
                deg[u]++;
            }
        }

        void ts(){

            vector<T>ans;
            set<T> q;

            for(auto node: deg){
                if(node.second == 0){
                    q.insert(node.first);
                }
            }
    
            while(!q.empty()){
                T front = (*q.begin());
                q.erase(q.begin());
                ans.push_back(front);

                for(auto node: adj[front]){
                        deg[node]--;
                        if (deg[node] == 0)
                        {  
                            q.insert(node);
                        }
                }
            }
            for(auto i: ans){
                cout<<i<<" ";
            }
            cout<<endl;
        }
};

int main(){
    int n,m;
    cin>>n>>m;
    graph<int> g(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    g.ts();

}