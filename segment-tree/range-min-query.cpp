#include<iostream>
#include<climits>
using namespace std;
#define M 100005
#define M2 2000005

void build(int node, int s, int e, int tree[], int arr[]){
    if(s == e){
        tree[node] = arr[s];
    }
    else{
        int mid = (s+e)/2;
        build(2*node, s, mid, tree, arr);
        build(2*node+1, mid+1, e, tree, arr);

        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

void update(int node, int s, int e, int idx, int val, int tree[], int arr[]){
    
    if(s == e){
        arr[s] = val;
        tree[node] = val;
    }
    else{
        int mid = (s+e)/2;
        if(idx >= s && idx <= mid){
            update(2*node, s, mid, idx, val, tree, arr);
        }
        else{
            update(2*node+1, mid+1, e, idx, val, tree, arr);
        }

        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node, int s, int e, int l, int r, int tree[]){
    if(s>r || e<l){
        return INT_MAX;
    }
    if(l <= s && r >= e){
        return tree[node];
    }
    
    int mid = (s+e)/2;
    int left = query(2*node, s, mid, l, r, tree);
    int right = query(2*node+1, mid+1, e, l, r, tree);

    return min(left,right);
}

int main(){
    int n, q;
    cin>>n>>q;
    int arr[M], tree[M2];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    build(1, 1, n, tree, arr);

    while(q--){
        char c;
        int l,r;
        cin>>c;
        if(c == 'q'){
            cin>>l>>r;
            cout<<query(1, 1, n, l, r, tree)<<endl;
        }
        else{
            cin>>l>>r;
            update(1, 1, n, l, r, tree, arr);
        }
    }
    return 0;
}