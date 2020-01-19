#include<iostream>
#include<map>
#include<iterator>
using namespace std;

class node{
    public:
    char val;
    map<char, node*> m;
    bool isEnd;

    node(char val):val(val),isEnd(false){}
};

class trieNode{
    node *root;

    public:
    trieNode(){
        root = new node('\0');
    }

    void insert(string s){
        node *temp = root;
        for(int i=0; i<s.length(); i++){
            if(temp->m.find(s[i]) == temp->m.end()){
                temp->m[s[i]] = new node(s[i]);
            }
            temp = temp->m[s[i]];
        }
        temp->isEnd = true;
    }

    bool search(string s){
        node *temp = root;
        for(int i=0; i<s.length(); i++){
            if(temp->m.find(s[i]) == temp->m.end()){
                return false;
            }
            temp = temp->m[s[i]];
        }
        
        printALlComb(temp, s);
        return true;
    }

    void printALlComb(node *root, string res){
        if(root->m.empty()){
            cout<<res<<endl;
            return;
        }
        if(root->isEnd){
            cout<<res<<endl;
        }

        string s;
        map<char, node *>::iterator it;
        for (it= root->m.begin(); it != root->m.end(); it++){
            s = res + root->m[it->first]->val;
            printALlComb(root->m[it->first], s);
        }
    }
};

int main(){
    int n;
    cin>>n;
    string s;
    trieNode root;
    for(int i=0; i<n; i++){
        cin>>s;
        root.insert(s);
    }
    int q;
    cin>>q;
    while (q--)
    {
       cin>>s;
       if(!root.search(s)){
           cout<<"No suggestion\n";
           root.insert(s);
       }
    }
    return 0;
}

