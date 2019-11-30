#include<bits/stdc++.h>
using namespace std;

bool check(vector<string> v, int r, int c, string s){
    int index = 0;
    int p,q,i,j;
    bool flag = false;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(v[i][j] == s[index]){
                p=i;
                q=j;
                flag = true;
                break;
            }
        }
    }
    if(!flag){
        return false;
    }
    index++;
    while(s[index] != '\0'){
        if(v[p][q] == s[index]);
        else if(p-1 >=0 && v[p-1][q] == s[index]){
            p = p-1;
        }
        else if (p - 1 >= 0 && v[p - 1][q] == s[index])
        {
            p = p - 1;
        }
        else if (q+ 1 < c && v[p][q+1] == s[index])
        {
            p = p + 1;
        }
        else if (q - 1 >= 0 && v[p][q-1] == s[index])
        {
            q = q - 1;
        }
        else{
            return false;
        }
        index++;
    }
    return true;
}

int main(){
    int r,c;
    cin>>r>>c;
    vector<string> v(r);
    for(int i=0; i<r; i++){
        cin>>v[i];
    }
    string s;
    cin>>s;
    if(check(v, r, c, s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}