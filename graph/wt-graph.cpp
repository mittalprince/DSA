#include<iostream>
#include<list>
#include<map>
#include<climits>
#include<set>
using namespace std;

template<typename T>
class graph{
    private:
        map<int, list<pair<int, int> > > adj;

    public:
        void addEdge(T u, T v, int dist, bool birdir=true){
            adj[u].push_back(make_pair(v, dist));
            if(birdir){
                adj[v].push_back(make_pair(u, dist));
            }
        }

        void print(){
            for(auto node: adj){
                cout<<node.first<<" --> ";
                for(auto child: node.second){
                    cout<<"("<<child.first<<","<<child.second<<")";
                }
                cout<<endl;
            }
        }

        int sssp(T src, T des){
            map<T, int>dist;
            map<T, T>parent;
            set<pair<int, T> >s;

            for (auto node : adj)
            {
                dist[node.first] = INT_MAX;
            }

            dist[src] = 0;
            parent[src] = src;
            s.insert(make_pair(0, src));

            while(!s.empty()){
                pair<int, T> front = (*s.begin());
                s.erase(s.begin());

                for(auto child: adj[front.second]){
                    if(dist[child.first] > front.first+child.second){
                        auto it = s.find(dist[child.first], child.first);
                        if(it !s.end()){
                            s.erase(it);
                        }
                        dist[child.first] = front.first+child.second;
                        parent[child.first] = front.second;
                        s.insert(make_pair(dist[child.first], child.first));
                    }
                }
            }

            for (auto node : dist)
            {
                cout << "Distance of " << node.first << " from " << src << " is " << node.second << endl;
            }

            T temp = des;
            while (temp != src)
            {
                cout << temp << "<--";
                temp = parent[temp];
            }
            cout << src << endl;

            return dist[des];
        }
};

int main(){
    
}