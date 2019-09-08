#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canPlace(int pgs[], int n, int m, int mid){

    int student = 1;
    int pg = 0;

    for(int i=0; i<n; i++){
        int x = pgs[i];
        if((pg+x) > mid){
            pg = x;
            student++;

            if(student > m){
                return false;
            }
        }
        else {
            pg += x;
        }
    }
    return true;
}

int main(){
    int n,m;
    int max=INT_MIN, sum=0;
    cin>>n>>m;
    int pgs[n];
    for(int i=0; i<n; i++){
        cin>>pgs[i];
        if(pgs[i]>max){
            max = pgs[i];
        }
        sum+=pgs[i];
    }


    int s=max; 
    int e=sum;
    int mid, ans=0;
    while(s<=e){
        mid = (s+e)>>1;
        if(canPlace(pgs,n, m, mid)){
            e = mid-1;
            ans = mid;
        }
        else{
            s = mid+1;
        }
    }

    cout<<ans<<endl;
    return 0;
}