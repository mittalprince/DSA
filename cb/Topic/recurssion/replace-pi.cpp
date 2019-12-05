#include<iostream>
using namespace std;

void replacePi(char *str, int i){

    if(str[i] == '\0'){
        return;
    }

    if(str[i] == 'p' && str[i+1] == 'i'){
        int j = i+2;
        while(str[j] != '\0'){
            j++;
        }
        while(j>=i+2){
            str[j+2] = str[j];
            j--;
        }

        str[i] = '3';
        str[i+1] = '.';
        str[i+2] = '1';
        str[i+3] = '4';
        return replacePi(str, i+4);
    }

    return replacePi(str, i+1);
}
int main(){
    char in[100];
    cin>>in;
    replacePi(in, 0);
    cout<<in<<endl;
    return 0;
}