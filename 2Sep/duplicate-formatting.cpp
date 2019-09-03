#include<bits/stdc++.h>
using namespace std;

void DF(char *a, int i){
    if(a[i] == '\0' || a[i+1] == '\0'){
        return;
    }
    
    if(a[i] == a[i+1]){
        int j = i+2;
        while(a[j] != '\0'){
            j++;
        }
        while(j >= i+2){
            a[j+1] = a[j];
            j--;
        }
        a[i+1]='*';
        a[i+2]=a[i];
        DF(a, i+2);
        return;
    }

    DF(a, i+1);
}
int main(){
    char a[100];
    cin>>a;
    DF(a, 0);
    cout<<a<<endl;
    return 0;
}