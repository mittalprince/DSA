#include<iostream>
#include<map>
using namespace std;

int main(){
    int n,k;
    map<int, int> m;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        m[arr[i]] = i;
    }

    int start = 0;
    int end = n;

    while(k && start<n && end>0){
        int index = m[end];

        if(start != index){
            swap(arr[start], arr[index]);
            m[arr[index]] = index;
            m[arr[start]] = start;
            k--;
        }
        start++;
        end--;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}