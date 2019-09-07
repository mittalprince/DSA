#include<iostream>
using namespace std;

void Unique(int arr[], int n){

    int count[64] = {0};
    for(int i=0; i<n; i++){
        int temp = arr[i];
        int k = 0;
        while(temp){
            if(temp&1){
                count[k]++;
            }
            k++;
            temp = temp>>1;
        }
    }

    for(int i=0; i<64; i++){
        count[i] = count[i]%3;
    }

    int ans = 0;
    for(int i=0; i<64; i++){
        if(count[i]){
            ans += (1<<i);
        }
    }

    cout<<ans<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Unique(arr, n);
    return 0;
}