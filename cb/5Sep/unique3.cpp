#include<iostream>
using namespace std;

void Unique(int arr[], int n){
    int digit[64] = {0};

    for(int i=0; i<n; i++){
        int k = 0;
        int temp = arr[i];
        while(temp){
            if(temp&1){
                digit[k]++;
            }
            k++;
            temp = temp>>1;
        }
    }

    for(int i=0; i<64; i++){
        digit[i] = digit[i]%3;
    }

    int ans = 0;
    for(int i=0; i<64; i++){
        if(digit[i]){
            ans += (1<<i);
        }
    }

    cout<<ans<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Unique(arr, n);
    return 0;

}