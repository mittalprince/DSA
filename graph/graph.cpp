#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int> adj[], int n){
    for(int i=0; i<n; i++){
        cout<<i;
        for(auto it: adj[i]){
            cout<<" -> "<<it;
        }
        cout<<endl;
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        addEdge(adj, u, v);
    }
    print(adj, v);
}