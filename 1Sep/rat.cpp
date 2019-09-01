#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define max 10

ll TW(ll arr[max][max], ll n, ll m, ll curr_row, ll curr_col, string str){
    if(arr[curr_row][curr_col] == 0){
        // str[str.length() -1] = '\0';
        return 0;
    }

    if( curr_row>=n || curr_col >= m){
        // str[str.length() -1] = '\0';
        return 0;
    }

    if((n-1) == curr_row && (m-1) == curr_col){
        cout<<str<<endl;
        return 1;
    }

    return TW(arr, n, m, curr_row, curr_col+1, str+'r') + TW(arr, n, m, curr_row+1, curr_col, str+'d');
}

int main(){
    ll n,m;
    cin>>n>>m;
    string str;
    ll arr[max][max];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<TW(arr, n, m, 0, 0, str)<<endl;
    return 0;

}