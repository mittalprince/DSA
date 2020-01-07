#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

class p{
    public:
    ll data;
    int idx;
};

class my_comp{
    public:
    bool operator()(p p1, p p2){
        return p1.data <= p2.data;
    }
};

int main(){
    int k,n;
    cin>>k>>n;

    vector<list<ll> >v(k);
    ll temp;
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin>>temp;
            v[i].push_back(temp);
        }
    }

    vector<ll> ans;
    priority_queue<p, vector<p>, my_comp > pq;

    for(int i=0; i<k; i++){
        p obj;
        obj.data = v[i].front();
        obj.idx = i;
        v[i].pop_front();
        pq.push(obj);
    }

    while(!pq.empty()){
        p obj = pq.top();
        pq.pop();
        ans.push_back(obj.data);

        if(!v[obj.idx].empty()){
            p inst_obj;
            inst_obj.data = v[obj.idx].front();
            inst_obj.idx = obj.idx;
            v[obj.idx].pop_front();
            pq.push(inst_obj);
        }
    }

    for(ll i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}