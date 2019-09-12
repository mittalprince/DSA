#include<iostream>
using namespace std;

void bubbleSort(int arr[], int i, int n){
    if(n == i){
        return;
    }
    if(i == n-1){
        return bubbleSort(arr, 0, n-1);
    }

    if(arr[i] > arr[i+1]){
        swap(arr[i], arr[i+1]);
    }

    return bubbleSort(arr, i+1, n);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bubbleSort(arr, 0, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}