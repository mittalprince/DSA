#include<bits/stdc++.h>
using namespace std;

int main(){
    
    priority_queue<int> ma; //max;
    priority_queue<int, vector<int>, greater<int> > mi; //min;

    int no;
    int median = INT_MIN;
    bool flag = true;
    while(scanf("%d", &no) != EOF){
        
        if(no == -1){
            cout<<median<<endl;
            if(flag){
                ma.pop();
            }
            else{
                mi.pop();
            }
        }
        else{
            if (no < median)
            {
                ma.push(no);
            }
            else
            {
                mi.push(no);
            }
        }

        int size1 = ma.size();
        int size2 = mi.size();

        if (size1 - size2 > 1)
        {
            int temp = ma.top();
            ma.pop();
            mi.push(temp);
        }

        if (size2 - size1 > 1)
        {
            int temp = mi.top();
            mi.pop();
            ma.push(temp);
        }

        if (size1 >= size2)
        {   flag = true;
            median = ma.top();
        }
        else{
            flag = false;
            median = mi.top();
        }
    }
    
}