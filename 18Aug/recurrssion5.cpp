#include<iostream>

using namespace std;

int last_7(int arr[], int n, int no){
    if(n == 0){
        return -1;
    }

    int idx = last_7(arr+1, n-1, no);
    if(idx != -1){
        return idx+1;
    }
    if(arr[0] == no){
        return 0;
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,7,9,7};
    cout<<last_7(arr, 7, 7)<<endl;
    return 0;
}