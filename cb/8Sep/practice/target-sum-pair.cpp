#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;

    sort(arr, arr+n);
    int l = 0;
    int r = n-1;

    while(l<r){
        if(arr[l]+arr[r] == sum){
            cout<<arr[l]<<" and "<<arr[r]<<endl;
            l++;
            r--;
        }
        else if (arr[l] + arr[r] > sum){
            r--;
        }
        else{
            l++;
        }
    }

    return 0;

}