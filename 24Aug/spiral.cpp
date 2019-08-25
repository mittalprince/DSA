#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Ans( vector< vector<int> > V){

    ll t,size,l,r,dir;
    
    t=0;
    size=v.size()-1;
    l=0;
    r=v[0].size()-1;
    
    dir =0;
    
    while(t<=size && l<=r){
        
        if(dir == 0){
            for(int i=l; i<=r;i++){
                cout<<v[t][i]<<", ";
            }
            t++;
        }
        
        if(dir == 1){
            for(int i=t;i<=size;i++){
                cout<<v[i][r]<<", ";
            }
            
            r--;
        }
        
        if(dir == 2){
            for(int i=r ; i>=l;i--){
                cout<<v[size][i]<<", ";
            }
            b = b-1;
        }
        
        if(dir == 3){
            for(int i=size;i>=t;i--){
                cout<<v[i][l]<<", ";
            }
            l=l+1;
        }
        
        dir = (dir+1)%4;
    }
}

int main(){
    
    ll r,c;
    cin>>r>>c;

    vector< vector<ll> >a(r, vector<ll>(c));

    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cin>>a[i][j];
        }
    }

    Ans(a);
    cout<<"END"<<endl;
    return 0;
    
}