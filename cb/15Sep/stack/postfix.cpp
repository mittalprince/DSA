#include<bits/stdc++.h>
using namespace std;

int main(){
    char exp[1000];
    cin>>exp;
    int j = 0;
    stack<int> s;
    while(exp[j] != '\0'){
        if(exp[j] == '+' || exp[j] == '-' || exp[j] == '*' || exp[j] == '/'){
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            int c;
            if(exp[j] == '+'){
                c = x+y;
            }
            else if(exp[j] == '-'){
                c = y-x;
            }
            else if(exp[j] == '*'){
                c = x*y;
            }
            else{
                c= y/x;
            }
            s.push(c);
        }
        else{
            s.push(exp[j]-'0');
        }
        j++;
    }
    cout<<s.top()<<endl;
    return 0;
}