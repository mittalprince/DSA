#include<bits/stdc++.h>
using namespace std;

int minSteps(string s1, string s2, int m, int n){
    if(n == 0){
        return m;
    }
    if(m == 0){
        return n;
    }
    
    if(s1[m-1] == s2[n-1]){
        return minSteps(s1, s2, m-1, n-1);
    }
    
    //insert m, n-1
    //delete m-1, n
    //replace  m-1, n-1
    int ans = min(minSteps(s1, s2, m, n-1), min(minSteps(s1, s2, m-1, n), minSteps(s1, s2, m-1, n-1)));

    return ans+1;
}

int BUminStesp(string s1, string s2, int m, int n){
    int arr[m+1][n+1];

    // for(int i=0; i<=m; i++){
    //     for(int j=0; j<=n; j++){
    //         // insert operation
    //         if(i==0){
    //             arr[i][j] = j;
    //         }
    //         // delete operation 
    //         else if(j==0){
    //             arr[i][j] = i;
    //         }
    //         //replace operation
    //         else if(str1[i-1] == str2[j-1]){
    //             arr[i]
    //         }

    //     }
    // }
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int m = s1.length();
    int n = s2.length();
    cout<<minSteps(s1, s2, m, n)<<endl;
}
