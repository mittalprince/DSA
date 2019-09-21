#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int i=0;
    stack<char> S;
    while(s[i] != '\0'){
        if(s[i] == '('){
            S.push(s[i]);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            S.push(s[i]);
            int j = i;
            while((s[i] != ')'&& s[i] != '(' ) && s[i] != '\0'){
                i++;
            }
            i-=2;
        }
        else if(s[i] == ')'){
            if(S.top() == '+' || S.top() == '-' || S.top() == '*' || S.top() == '/'){
                S.pop();
                if(S.top() == '('){
                    S.pop();
                }
            }
            else{
                cout<<"YES"<<endl;
                return 0;
            }
        }
        i++;
    }

    if(S.empty()){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }

}
