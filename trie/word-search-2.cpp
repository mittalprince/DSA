#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Node{
    public:
    bool isEnd;
    string val;
    Node *arr[26];

    Node(){
        isEnd = false;
        for(int i=0; i<26; i++){
            arr[i] = NULL;
        }
    }
    ~Node()
    {
        for(auto i=0; i<26; ++i) delete arr[i];
    }
};

class Trie{
    public:
    Node *root;

    Trie(){
        root = new Node();
    }
    ~Trie()
    {
        delete root;
    }

    void insert(vector<string>& words){
        int n = words.size();
        for(int i=0; i<n; i++){
            Node *temp = root;
            for(char c: words[i]){
                if(temp->arr[c-'a'] == NULL){
                    temp->arr[c-'a'] = new Node();
                }
                temp = temp->arr[c-'a'];
            }
            temp->isEnd = true;
            temp->val = words[i];
        }
    }

    void search(Node *root, vector<vector<char>> &board, int i, int j, vector<string>&ans){
        if(board[i][j] == 'X'){
            return;
        }
        if(root->arr[board[i][j]-'a'] == NULL){
            return;
        }
        else{
            char temp = board[i][j];
            root = root->arr[temp-'a'];
            if(root->isEnd){
                ans.push_back(root->val);
                root->isEnd = false;
            }
            board[i][j] = 'X';
            if(i+1<board.size()){
                search(root, board, i+1, j, ans);
            }
            if(i>0){
                search(root, board, i-1, j, ans); 
            }
            if(j+1<board[0].size()){
                search(root, board, i, j+1, ans);
            }
            if(j>0){
                search(root, board, i, j-1, ans);
            }
            board[i][j] = temp;
            return;
        }

    }
};

class Solution{
    public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int n = board.size();
        if(!n){
            return ans;
        }
        int m = board[0].size();
        if(!m){
            return ans;
        }
        int N = words.size();
        if(!N){
            return ans;
        }

        Trie root;
        root.insert(words);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                root.search(root.root, board, i, j, ans);
           }
        }
        return ans;
    }
};

int main(){

}