#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char, Node* > m;
        bool isterminating;

        Node(char d):data(d),isterminating(false){} 
};

class trie{
    Node* root;

    public: 
        trie(){
            root = new Node('\0');
        }

        void insert(string s){
            Node* temp = root;

            for(int i=0; i<s.length(); i++){
                if(temp->m.find(s[i]) == temp->m.end()){
                    temp->m[s[i]] = new Node(s[i]);
                    
                }
                temp = temp->m[s[i]];
            }

            temp->isterminating = true;
        }

        bool search(string s){
            Node* temp = root;


            for(int i=0; i<s.length(); i++){
                if(temp->m.find(s[i]) == temp->m.end()){
                    return false;
                }
                temp = temp->m[s[i]];
            }

            return temp->isterminating;
        }
};


int main(){
    trie t;
    t.insert("mango");
    t.insert("apple");
    t.insert("man");
    t.insert("appe");

    cout<<t.search("mango")<<endl;
    cout<<t.search("apple")<<endl;
    cout<<t.search("app")<<endl;
}