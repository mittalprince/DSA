#include<iostream>
using namespace std;

class node{
    int val;
    node *left, *right;

    public:
    node(int val):val(val),left(NULL),right(NULL){}

    string serialise(node *root){
        string res = "";
        if(root == NULL){
            return "#";
        }

        res+= to_string(root->val)+","+serialise(root->left)+serialise(root->right);
        return res;
    }

    node* deserailise(string data){
        if(data == "#"){
            return NULL;
        }
        stringstream s(data);
        node *ans = makeSerial(s);
    }

    node* makeSerial(stringstream &s){
        string temp;
        getline(s, temp, ',');
        if(temp == "#"){
            return NULL;
        }
        node *root = new node(stoi(temp));
        root->left = makeSerial(s);
        root->right = makeSerial(s);
        return root;
    }
};

int main(){
    node *root = NULL;
    
}
