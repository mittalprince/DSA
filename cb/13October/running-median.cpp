#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        priority_queue<int> ma; //max;
        priority_queue<int, vector<int>, greater<int> > mi; //min;

        int no;
        int median = INT_MIN;
        bool flag = true;
        while(scanf("%d", &no) != EOF){
            // cout<<no<<" ";
            if(no == 0){
                // cout<<"No";
                ma = priority_queue<int>();
                mi = priority_queue<int, vector<int>, greater<int> >();
                median = INT_MAX;
                printf("\n");
                continue;
            }
            if(no == -1){
                int size1 = ma.size();
                int size2 = mi.size();

                if(size1 >= size2){
                    median = ma.top();
                    ma.pop();
                }
                else{
                    median = mi.top();
                    mi.pop();
                }
                printf("%d\n", median);
            }
            else{
                if(ma.empty() && mi.empty()){
                    ma.push(no);
                }
                else{
                    if(no < median){
                        // cout<<"max"<<no<<endl;
                        ma.push(no);
                    }
                    else{
                        // cout<<"min"<<no<<endl;
                        mi.push(no);
                    }
                }
            }
            int size1 = ma.size();
            int size2 = mi.size();

            if (size1 - size2 > 1)
            {
                int temp = ma.top();
                ma.pop();
                mi.push(temp);
                // cout<<"Min"<<temp<<endl;
            }

            if (size2 - size1 > 1)
            {
                int temp = mi.top();
                mi.pop();
                ma.push(temp);
                // cout<<"Max"<<temp<<endl;
            }

            if(size1 >= size2){
                median = ma.top();
            }
            else{
                median = mi.top();
            }

        }
    }
    
}