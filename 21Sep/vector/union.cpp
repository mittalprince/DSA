#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

int main(){
    int arr[] = {1,2,3,3,2,1};
    int arr2[] = {7,7,7,7,7,7};
    set<int> s;
    unordered_map<int , int> m;
    for(int i=0; i<6; i++){
        s.insert(arr[i]);
        m[arr[i]] = 1;
    }

    for (int i = 0; i < 6; i++)
    {
        s.insert(arr2[i]);
        if(m[arr2[i]] == 1){
            m[arr2[i]] = 2;
        }
    }

    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;
    for (auto i : m)
    {   
        if(i.second == 2){
            cout << i.first << " ";
        }    
    }
    return 0;

}