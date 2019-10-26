#include<bits/stdc++.h>
using namespace std;
#define max 100000

int setBits(int n){
    int arr[max] = {0};
    arr[1] = 1;
    arr[2] = 1;

    int ans = 2;
    for(int i=3; i<=n; i++){
        if(i&1){
            arr[i] = arr[i>>1]+1;
            ans += arr[i];
        }
        else{
            arr[i] = arr[i>>1];
            ans += arr[i];
        }
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<setBits(n)<<endl;
}