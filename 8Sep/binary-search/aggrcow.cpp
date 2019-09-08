#include<bits/stdc++.h>
using namespace std;

bool canPlace(int c, int n, int stalls[], int sep){
    int cow=1;
    int loc = stalls[0];

    for(int i=1; i<n; i++){
        int x = stalls[i];
        if( (x-loc) >= sep){
            cow++;
            loc = x;

            if(cow == c){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,c;
    cin>>n>>c;

    int stalls[n];
    for(int i=0; i<n; i++){
        cin>>stalls[i];
    }

    sort(stalls, stalls+n);

    int s = 0;
    int e = stalls[n-1]-stalls[0];
    int mid,ans=0;
    while(s<=e){
        mid = (s+e)>>1;
        if(canPlace(c,n,stalls,mid)){
            ans = mid;
            s= mid+1;
        }
        else{
            e= mid-1;
        }
    }

    cout<<ans<<endl;
    return 0;
}