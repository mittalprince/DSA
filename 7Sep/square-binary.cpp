#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int start = 0;
    int end = n/2;
    int mid;
    int ans = 0;
    while(start <= end){
        mid = (start + end) / 2;
        if(mid*mid == n){
            ans = mid;
            break;
        }
        else if(mid*mid < n){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
   
}