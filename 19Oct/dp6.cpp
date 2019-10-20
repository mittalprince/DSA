#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n){

    if(m==0 || n==0){
        return 0;
    }

    if(s1[m-1] == s2[n-1]){
        return 1+lcs(s1, s2, m-1, n-1);
    }
    else{
        return max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
    }

}

void bulcs(string s1, string s2, int m, int n){
    int l[m+1][n+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                l[i][j] = 0;
            }

            else if(s1[i-1] == s2[j-1]){
                l[i][j] = l[i-1][j-1]+1;
            }
            else{
                l[i][j] = max(l[i][j-1], l[i-1][j]);
            }
        }
    }

    cout<<"LCS length "<<l[m][n]<<endl;
    int index = l[m][n];

    char ans[index+1];
    ans[index] = '\0';

    int start = m, end = n;
    while(start > 0 && end > 0){

        if(s1[start-1] == s2[end-1]){
            ans[index-1] = s1[start-1];
            start--;
            end--;
            index--;
        }
        else if(l[start-1][end] > l[start][end-1]){
            start--;
        }
        else{
            end--;
        }
    }

    cout<<ans<<endl;
}

int main(){
    string str1, str2;
    cin>>str1>>str2;
    
    int m = str1.length();
    int n = str2.length();

    cout<<lcs(str1, str2, m,n)<<endl;
    bulcs(str1, str2, m, n);
}