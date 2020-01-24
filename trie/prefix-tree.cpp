#include<iostream>
using namespace std;

class Node{
    public:
    bool isEnd;
    Node *arr[26];
    Node(){
        isEnd = false;
        for(int i=0; i<26; i++){
            arr[i] = NULL;
        }
    }
};

class Trie{
    Node *root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node *temp = root;
        for(char c: word){
            if(temp->arr[c-'a'] == NULL){
                temp->arr[c-'a'] = new Node();
            }
            temp = temp->arr[c-'a'];
        }

        temp->isEnd = true;
    }

    bool search(string word){
        Node *temp = root;
        for(char c: word){
            if(temp->arr[c-'a'] == NULL){
                return false;
            }
            temp = temp->arr[c-'a'];
        }
        return temp->isEnd;
    }

    bool startsWith(string word){
        Node *temp = root;
        for(char c: word){
            if(temp->arr[c-'a'] == NULL){
                return false;
            }
            temp = temp->arr[c-'a'];
        }
        return true;
    }
};

int main(){
    Trie root;

}