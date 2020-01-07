#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define max 100005

int check(int arr[][max], int s, int e, int I, int J){
        // cout<<s<<" "<<e<<" "<<I<<" "<<J<<endl;

    ll mid1 = (I+s)/2;
    ll mid2 = (J+e)/2;
    
    // if(arr[s+1][mid2] != arr[mid1][e+1]){
    //     return 0;
    // }
    
    
    ll left=e, right=J;
    while(left<right){
        if(arr[mid1][left] != arr[mid1][right]){
            return 0;
        }
        left++;
        right--;
    }
    ll top=s, bottom=I;
    while(top<bottom){
        if(arr[top][mid2] != arr[bottom][mid2]){
            return 0;
        }
        top++;
        bottom--;
    }
        // cout<<s<<" "<<e<<" "<<I<<" "<<J<<endl;
    
    if(arr[top][mid2] != arr[mid1][left]){
        return 0;
    }
    return 1;
}
int check1(int **arr, int s, int e, int I, int J){
        // cout<<s<<" "<<e<<" "<<I<<" "<<J<<endl;

    int mid1 = (I+s)/2;
    int mid2 = (J+e)/2;
    
    // if(arr[s+1][mid2] != arr[mid1][e+1]){
    //     return 0;
    // }
    
    
    ll left=e, right=J;
    while(left<right){
        if(arr[mid1][left] != arr[mid1][right]){
            return 0;
        }
        left++;
        right--;
    }
    ll top=s, bottom=I;
    while(top<bottom){
        if(arr[top][mid2] != arr[bottom][mid2]){
            return 0;
        }
        top++;
        bottom--;
    }
        // cout<<s<<" "<<e<<" "<<I<<" "<<J<<endl;
    
    if(arr[top][mid2] != arr[mid1][left]){
        return 0;
    }
    return 1;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m,temp;
	    ll ans = 0;
	    cin>>n>>m;
	    if(n<1000){
	        int arr[n][max];
	    
    	    for(int i=0; i<n; i++){
    	        for(int j=0; j<m; j++){
    	            cin>>arr[i][j];
    	        }
    	    }
    	    
    	    for(int i=0; i<n; i++){
    	        for(int j=0; j<m; j++){
    	            
    	            for(int k=2; i+k<n && j+k<m; k+= 2){
    	               // if(i+k < n && j+k < m)
    	                    ans += check(arr, i, j, i+k, j+k);
    	                   //ans += 1;
    	            }   
    	        }
    	    }   
	    }
	    else{
	        int** arr = new int*[n];
            for(int i = 0; i < n; ++i){
                arr[i] = new int[m];   
            }
	    
    	    for(int i=0; i<n; i++){
    	        for(int j=0; j<m; j++){
    	            cin>>arr[i][j];
    	        }
    	    }
    	    
    	    for(int i=0; i<n; i++){
    	        for(int j=0; j<m; j++){
    	            
    	            for(int k=2; i+k<n && j+k<m; k+= 2){
    	               // if(i+k < n && j+k < m)
    	                    ans += check1(arr, i, j, i+k, j+k);
    	                   //ans += 1;
    	            }   
    	        }
    	    }
    	    
    	    for(ll i = 0; i < m; ++i) {
                delete [] arr[i];
            }
                delete [] arr;
	    }
	   
	   // vector<vector<int> > arr(n, vector<int> (m, 0));
	    
	    
	    ans += (n*m);
	    
	    cout<<ans<<endl;
	}
	return 0;
}