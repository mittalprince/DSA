#include<iostream>
using namespace std;

int kadanes(int n, int arr[]){
    int cs = 0, ms = 0;
    for(int i=0; i<n; i++){
        cs += arr[i];
        if (cs < 0)
        {
            cs = 0;
        }
        if (ms < cs)
        {
            ms = cs;
        }
    }

    return ms;
}

int maxSum(int n, int arr[]){

    int firstOpt = kadanes(n, arr);

    int totSum = 0;
    for(int i=0; i<n; i++){
        totSum += arr[i];
        arr[i] = -arr[i];
    }

    totSum = totSum + kadanes(n, arr);

    return firstOpt > totSum ? firstOpt : totSum;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Max Circular Subaary Sum is " << maxSum(n, arr) << "\n";
    }
    
    return 0;
}

// https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/