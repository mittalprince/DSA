#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key){
    
    if(n == 0){
        return -1;
    }

    if(arr[0] == key){
        return 0;
    }
    int index = linearSearch(arr + 1, n - 1, key);

    if(index != -1){
        return index+1;
    }
    return -1;
}

int last_occurrence(int arr[], int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    int index = last_occurrence(arr + 1, n - 1, key);
    if (index != -1)
    {
        return index + 1;
    }
    if (arr[0] == key)
    {
        return 0;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<linearSearch(arr, n, key)<<endl;
    cout<<last_occurrence(arr, n, key)<<endl;
    return 0;
}