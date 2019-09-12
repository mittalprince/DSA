#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){
    
}
void mergeSort(int arr[], int s, int e){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    return merge(arr, s, e);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

}