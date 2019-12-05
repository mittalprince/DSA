#include<iostream>

using namespace std;

bool isSorted(int arr[], int n){
    if(n ==1){
        return true;
    }
    return (arr[0] <= arr[1] && isSorted(arr+1, n-1));

}
int main(){

    int arr[] = {1,2,2,5,7};
    cout<<isSorted(arr, 5)<<endl;
    return 0;
}