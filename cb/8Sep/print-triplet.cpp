#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum = 0;
    cin>>sum;

    sort(arr, arr+n);

    for(int i=0; i<n-1; i++){
        int l=i+1;
        int r = n-1;
        int x = arr[i];

        while(l<r){
            if(x +arr[l]+arr[r] == sum){
                cout<<x<<", "<<arr[l]<<" and "<<arr[r]<<endl;
                l++;r--;
            }
            else if (x + arr[l] + arr[r] > sum){
                r--;
            }
            else{
                l++;
            }
        }
    }

    return 0;
}