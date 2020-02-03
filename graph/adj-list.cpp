#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class graph{
    private:
        map<T, list<T> >adj;

        void DFSHelper(T src, map<T, bool> &visited){
            cout<<src<<" ";
            visited[src] = true;

            for(auto child: adj[src]){
                if(!visited[child]){
                    DFSHelper(child, visited);
                }
            }
        }

    public:

        void addEdge(T u, T v, bool bidir=true){
            adj[u].push_back(v);
            if(bidir){
                adj[v].push_back(u);
            }
        }

        void print(){
            for(auto node: adj){
                cout<<node.first;
                for(auto child: adj[node.first]){
                    cout<<" -> "<<child;
                }
                cout<<endl;
            }
        }

        void BFS(T src){
            queue<T> q;
            map<T, bool> visited;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                T front = q.front();
                q.pop();
                cout<<front<<", ";
                for(auto node: adj[front]){
                    if(!visited[node]){
                        q.push(node);
                        visited[node] = true;
                    }
                }
            }
            cout<<endl;
        }

        void DFS(T src){
            map<T, bool>visited;
            int comp = 1;
            
            DFSHelper(src, visited);

            for(auto node: adj){
                if(!visited[node.first]){
                    comp++;
                    DFSHelper(node.first, visited);
                }
            }

            cout<<endl;
            cout<<"Total Component "<<comp<<endl;
        }

        int sssp(T src, T des){
            map<T, int>dist, parent;

            for(auto it: adj){
                dist[it.first] = INT_MAX;
            }

            queue<T>q;
            q.push(src);
            dist[src] = 0;
            parent[src] = src;

            while(!q.empty()){
                T front = q.front();
                q.pop();

                for(auto node: adj[front]){
                    if(dist[node] > dist[front]+1){
                        dist[node] = dist[front]+1;
                        parent[node] = front;
                        q.push(node);
                    }
                }
            }

            for(auto node: dist){
                cout<<"Distance of "<<node.first<<" from "<<src<<" is "<<node.second<<endl;
            }
            T temp = des;

            while(temp != src){
                cout<<temp<<" <-- ";
                temp = parent[temp];
            }

            return dist[des];
         }
};

int main(){
    graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(4,2);
	g.addEdge(3,2);
	g.addEdge(3,4);
	g.addEdge(3,5);

	g.addEdge(10,5);
	g.addEdge(15,10);
	g.addEdge(15,200);
	g.addEdge(160,200);

    // g.print();
    // cout<<endl;

    // g.BFS(0);
    // cout<<endl;
	
    // g.DFS(0);
    // cout<<endl;

    cout<<g.sssp(0,5)<<endl;

}