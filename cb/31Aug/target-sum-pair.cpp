#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int *start = arr;
    int *last = arr+n;
    int target;
    cin>>target;
    while(start<last){
        if((*start + *last) >target){
            last--;
        }
        if ((*start + *last) < target){
            start++;
        }
        if ((*start + *last) == target){
            cout<<*start<<" and "<<*last<<endl;
            start++;
            last--;
        }

    }
    return 0;
}