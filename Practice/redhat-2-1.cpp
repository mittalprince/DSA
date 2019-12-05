#include<bits/stdc++.h>
using namespace std;

void pattern(int N){
    int n = 2*N-1;
    int t,d,l,r;
    t=0,d=n,l=0,r=n;
    int cycle = 0;
    int arr[n][n];
    while(l<r && t<d){

        if(cycle == 0){
            for(int i=l; i<r; i++){
                arr[t][i] = N;
            }
            t++;
            cycle++;
        }
        if (cycle == 1)
        {
            for (int i = t; i < d; i++)
            {
                arr[i][r-1] = N;
            }
            r--;
            cycle++;
        }
        if (cycle == 2)
        {
            for (int i = r-1; i >=l; i--)
            {
                arr[d-1][i] = N;
            }
            d--;
            cycle++;
        }
        if (cycle == 3)
        {
            for (int i = d-1; i >= t; i--)
            {
                arr[i][l] = N;
            }
            l++;
            cycle++;
        }

        if(cycle == 4){
            N--;
            cycle = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    pattern(n);
}