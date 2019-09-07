#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int count = 0;
        for(int i=n; i<=m; i++){
            int temp = i;
            while(temp){
                if(temp&1){
                    count++;
                }
                temp = temp>>1;
            }
        }
        cout<<count<<endl;   
    }
    return 0;
}
