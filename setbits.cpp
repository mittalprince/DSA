#include<iostream>
using namespace std;
typedef unsigned long long ll;

int set_bits[16] = {0, 1, 1, 2, 1, 2, 2, 3,  
                    1, 2, 2, 3, 2, 3, 3, 4};  
  
unsigned int countSetBits(unsigned int n)  
{  
    int BIT = 0;  
    if (n == 0)  
        return set_bits[0];  
     
    BIT = n & 0xf;    
    return set_bits[BIT] + countSetBits(n >> 4);  
} 
int main(){
    int  t;
    cin>>t;
    while(t--){
        int a,b;
        unsigned int ct=0;
        cin>>a>>b;
        if(a<0){
            a = abs(a);
            for(int i=a; i>0; i--){
                int x = ~(i-1);
                ct += countSetBits(x);
            }
            for(ll i=0; i<=b; i++){
                ct += countSetBits(i);
            }
        }
        else{
            for(ll i=a; i<=b; i++){
                ct += countSetBits(i);
            }
        }
        
        cout<<ct<<endl;
    }
    return 0;
}
   