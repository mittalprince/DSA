#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int i=s, j=mid+1, k=s;
    int temp[e];
    while(i<=mid && j<=e){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }    

    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=e){
        temp[k] = arr[j];
        k++;
        j++;
    }

    for(int i=s; i<=e; i++){
        arr[i] = temp[i];
    }
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
    mergeSort(arr, 0, n); 
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}