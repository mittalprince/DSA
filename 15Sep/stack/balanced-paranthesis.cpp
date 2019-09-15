#include<bits/stdc++.h>
using namespace std;

int main(){

    char bp[1000];
    cin>>bp;
    int i = 0;
    stack<char> s;
    while(bp[i]  != '\0'){
        if(bp[i] == '{' || bp[i] == '(' || bp[i] == '['){
            s.push(bp[i]);
        }
        else{
            if(bp[i] == ')' && s.top() == '('){
                s.pop();
            }
            else if(bp[i] == '}' && s.top() == '{'){
                s.pop();
            }
            else if(bp[i] == ']' && s.top() == '['){
                s.pop();
            }
        }
        i++;
    }

    if(s.empty()){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}
