#include<bits/stdc++.h>

using namespace std;

bool palidrome(char a[], int s, int e){
    
    if(s == e || s>e){
        return true;
    }
    
    if(a[s] != a[e]){
        return false;
    }
    return palidrome(a, s+1, e-1);
}

int main(){
    
    char a[1000];
    cin.getline(a, 1000);
    int j =0 ;
    while(a[j] != '\0'){
        j++;
    }
    // cout<<j<<endl;
    if(palidrome(a, 0, j-1)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
    
}