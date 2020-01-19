#include<iostream>
#include<unordered_map>
using namespace std;
#define mod 1000000007

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int j=0;
    long long ans = 0;
    unordered_map<int, bool> m;
    for(int i=0; i<n; i++){
        while(j<n && m.find(arr[j]) == m.end()){
            m[arr[j]] = true;
            j++;
        }

        // here we calculate sum of length of all sub sequence start with arr[i]
        ans += (((j-i)*(j-i+1))>>1)%mod;

        // after each iteration we remove the current arr[i] element from map as 
        // it may be one of the repetitive element ( see while condition in upper loop)

        /*
        if there is no repitiive element in given array we have j = n in first loop of i,
        and then we normally just calulate sum of length of sequnce starting with arr[i] which chnages at every iteration
        */

       /*
       if there is any repition we first cal longest non reptitive sequence and 
       cal len sum for each sequence starting with arr[i] and remove it from map so that can check whther is it the repeating element or not
       */
        m.erase(arr[i]);
    }

    cout<<ans<<endl;
}

/* 

Logic -----------------------

1. we first find the longest sub sequence having all distinct elements

The logic is that once you have identified a distinct subarray lets assume it to be [i,........,j] then the no of subarrays starting with i
(the lengths of these subarrays are (j-i+1) similarly for subarrays starting with i+1,.....etc
Let's understand this with an example:
say we have identified arr[i,j]=[1,2,3,4]
subarrays starting with 1 : {1},{1,2}, {1,2,3},{1,2,3,4} // length 10
subarrays starting with 2 : {2},{2,3}, {2,3,4} // lenght 6
subarrays starting with 3 : {3},{3,4} // length 2
subarrays starting with 4: {4} // length 1
sum of lengths of subarrays starting with 1:includes as much elements as 1+2+3+4
sum of lengths of subarrays starting with 2:includes as much elements as 1+2+3 //here the code increases i

*/