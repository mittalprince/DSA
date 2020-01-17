#include<iostream>
#include<unordered_map>
using namespace std;

class node{
    public:
    char ch;
    unordered_map<char, node*> m;
    int wt;
    bool isEnd;

    node(char ch, int wt=0):ch(ch),isEnd(false),wt(wt){}
};

class trieNode{
    node* root;

    public:

    trieNode(){
        root = new node('\0');
    }
    void insert(string s, int wt){
        node *temp = root;
        for(int i=0; i<s.length(); i++){
            if(temp->m.find(s[i]) == temp->m.end()){
                temp->m[s[i]] = new node(s[i], wt);
            }
            temp = temp->m[s[i]];
            temp->wt = max(wt, temp->wt);
        }
        temp->isEnd = true;
    }

    int search(string s){
        node *temp = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (temp->m.find(s[i]) == temp->m.end())
            {
                return -1;
            }
            temp = temp->m[s[i]];
        }
        return temp->wt;
    }
};

int main(){
    int n,q,wt;
    cin>>n>>q;
    string s;
    trieNode root;
    for(int i=0; i<n; i++){
        cin>>s;
        cin>>wt;
        root.insert(s, wt);
    }
    while(q--){
        cin>>s;
        int temp = root.search(s);
        cout<<temp<<endl;
    }
}
