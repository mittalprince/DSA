#include<iostream>
#include<climits>
using namespace std;
#define M 100005
#define M2 2000005

void build(int tree[], int arr[], int n){
    for(int i=0; i<n; i++){
        tree[n+i] = arr[i];
    }
    for(int i=n-1; i>=1; i--){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
}

void update(int tree[], int pos, int val, int n){
    pos += n;

    tree[pos] = val;
    while(pos > 1){
        pos = pos/2;
        tree[pos] = min(tree[2*pos], tree[2*pos+1]);
    }
}

int query(int tree[], int l, int r, int n){
    l += n;
    r += n;

    int ans = INT_MAX;
    while(l<r){
        if(l&1){
            ans = min(ans, tree[l]);
            l++;
        }
        if(r&1){
            r--;
            ans = min(ans, tree[r]);
        }

        l = l/2;
        r = r/2;
    }

    return ans;
}
int main(){
    int n,q;
    cin>>n>>q;
    int arr[M], tree[M2];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    build(tree, arr, n);
    while(q--){
        char c;
        int l,r;
        cin>>c;
        if(c == 'q'){
            cin>>l>>r;
            l--;r--;
            cout<<query(tree, l, r, n)<<endl;
        }
        else{
            cin>>l>>r;
            l--;
            arr[l] = r;
            update(tree, l, r, n);
        }
    }
}