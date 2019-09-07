#include<iostream>
using namespace std;

int nqueen(int n, int row, int ld, int rd){

    // hum sirf curretn row  ke bare mein dekhenge ki kha kha queen place kar sakta hai
    // curretn argument yahi batata hai kissi kiss jagah par queen exist karti hai
    int done = (1<<n)-1;
    if(done == row){
        // got a possible solution
        return 1;
    }

    int pos = done&(~(row|ld|rd)); // current row mein kitne column mein queen rakh sakta hoo jha jha 1 hai vha queen rakh sakta hoo;

    int ans = 0;
    while(pos>0){ // how many possibility to place a queen in a row
        int p = pos&(-pos); // konsi position par queen place ki hai 
        pos -= p; // abb kitni possible jagah hai kissi row mein queen place karne ki 
        ans += nqueen(n, (row|p), (ld|p)<<1, (rd|p)>>1);
    }

    // (row|p) = phela kha kha kar chuka hai aur abb vala ki position ka sum
    // (ld|p)<<1 = phela vala diagonal and abb vali queen ka left diagonal
    // (rd|p)>>1 = phela vala diagonal and abb vali queen ka right diagonal
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<nqueen(n, 0, 0, 0)<<endl;
    return 0;
}

