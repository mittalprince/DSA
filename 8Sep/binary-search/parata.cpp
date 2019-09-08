#include<bits/stdc++.h>
using namespace std;

int maxTime(int rank, int n){
    int time = 0;
    for(int i=1; i<=n; i++){
        time += (rank*i);
    }
    return time;
}

bool canMake(int rank[], int r, int parta, int time){
    int total_parata = 0;

    for(int i=0; i<r; i++){
        int ct = 0;
        int temp = time;
        int t = rank[i];
        while(temp > 0){
            temp -= t;
            if (temp > 0)
            {
                ct++;
                t += t;
            }
        }
        // ct--;
        total_parata +=  ct;
    }
    if(total_parata > parta){
        return true;
    }
    return false;
}
int main(){
    int p, r;
    cin>>p>>r;
    int rank[r];
    for(int i=0; i<r; i++){
        cin>>rank[i];
    }
    int s=0;
    int e = maxTime(rank[0], p);
    int mid,ans=0;
    while(s<=e){
        mid = (s+e)>>1;
        if(canMake(rank, r, p, mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    cout<<ans<<endl;
    return 0;
}