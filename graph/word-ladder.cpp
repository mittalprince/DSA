#include<iostream>
#include<set>
#include<queue>
using namespace std;

int shortestChainLen(string start, string target, set<string> &D){
    if (D.find(target) == D.end()) return 0;
    int level=0, wordlen=target.length();

    queue<string>q;
    q.push(start);

    while(!q.empty()){
        level++;
        int qSize = q.size();

        for(int i=0; i<qSize; i++){
            string curr = q.front();
            q.pop();

            for(int pos=0; pos<wordlen; pos++){
                char act_val = curr[pos];

                for(char c='a'; c<= 'z'; c++){
                    curr[pos] = c;

                    if(curr == target){
                        return level+1;
                    }

                    if(D.find(curr) == D.end()) continue;
                    D.erase(curr);
                    q.push(curr);
                }

                curr[pos] = act_val;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    set<string> s;
    string input;
    for(int i=0; i<n; i++){
        cin>>input;
        s.insert(input);
    }
    string start, target;
    cin>>start>>target;

    cout<<shortestChainLen(start, target, s)<<endl;
}