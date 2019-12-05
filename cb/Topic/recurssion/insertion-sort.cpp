#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    if(n == 1 || n == 0){
        return;
    }

    insertionSort(arr, n-1);
    int key = arr[n-1];
    int j = n-2;

    while(j>=0 && arr[j]>key){
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = key;

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}