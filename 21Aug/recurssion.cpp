#include<bits/stdc++.h>

using namespace std;

void searchInc(int arr[], int n, int index, int no){
    if(n == 0){
        return;
    }
    if(arr[0] == no){
        cout<<index+1<<" ";
    }
    searchInc(arr+1, n-1, index+1, no);
}

void searchDec(int arr[], int n, int index, int no){
    if(n == 0){
        return;
    }
    searchDec(arr+1, n-1, index+1, no);
    if(arr[0] == no){
        cout<<index+1<<" ";
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    searchInc(arr, n, 0, 7);
    cout<<endl;
    searchDec(arr, n, 0, 7);
    cout<<endl;
    return 0;
}