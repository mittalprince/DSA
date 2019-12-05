#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Ans( vector< vector<ll> > V){

    ll t,size,l,r,dir;
    
    t=0;
    size=V.size()-1;
    l=0;
    r=V[0].size()-1;
    
    dir =0;
    
    while(t<=size && l<=r){
        
        if(dir == 0){
            for(int i=l; i<=r;i++){
                cout<<V[t][i]<<", ";
            }
            t++;
        }
        
        if(dir == 1){
            for(int i=t;i<=size;i++){
                cout<<V[i][r]<<", ";
            }
            
            r--;
        }
        
        if(dir == 2){
            for(int i=r ; i>=l;i--){
                cout<<V[size][i]<<", ";
            }
            size = size-1;
        }
        
        if(dir == 3){
            for(int i=size;i>=t;i--){
                cout<<V[i][l]<<", ";
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