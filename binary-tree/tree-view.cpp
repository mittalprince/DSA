#include<iostream>
#include<queue>
#include<map>
#include<iterator>
#include<vector>
#include<utility>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d),left(NULL),right(NULL){}
};

void bottomView(node *root){
    if(root == NULL){
        return;
    }
    
    map<int, int> m;

    queue<pair<node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        m[temp.second] = temp.first->data;
        if(temp.first->left){
            q.push(make_pair(temp.first->left, temp.second-1));
        }
        if(temp.first->right){
            q.push(make_pair(temp.first->right, temp.second+1));
        }
    }

    map<int, int>::iterator it = m.begin();
    for(; it!= m.end(); it++){
        cout<<it->second<<" ";
    }
    cout<<endl;
}

void topView(node *root){
    if(root == NULL){
        return;
    }
    
    map<int, int> m;

    queue<pair<node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        if(m.find(temp.second) == m.end()){
            m[temp.second] = temp.first->data;
        }
        if(temp.first->left){
            q.push(make_pair(temp.first->left, temp.second-1));
        }
        if(temp.first->right){
            q.push(make_pair(temp.first->right, temp.second+1));
        }
    }

    map<int, int>::iterator it = m.begin();
    for(; it!= m.end(); it++){
        cout<<it->second<<" ";
    }
    cout<<endl;
}

void verticalView(node *root){
    if(root == NULL){
        return;
    }
    
    map<int, vector<int> >m;

    queue<pair<node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        m[temp.second].push_back(temp.first->data);
        if(temp.first->left){
            q.push(make_pair(temp.first->left, temp.second-1));
        }
        if(temp.first->right){
            q.push(make_pair(temp.first->right, temp.second+1));
        }
    }

    map<int, vector<int> >::iterator it = m.begin();
    for(; it!= m.end(); it++){
        vector<int>::iterator t = it->second.begin();
        for(; t != it->second.end(); t++){
            cout<<*t<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}

void rightView(node *root){
    if(root == NULL){
        return;
    }
    
    vector<int> v;
    int level = 1;

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();

        if(temp){
            v.push_back(temp->data);

            while(q.front() != NULL){

                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->left){
                    q.push(temp->left);
                }

                q.pop();
                temp = q.front();
            }
            q.push(NULL);
        }
        q.pop();
    }

    vector<int>::iterator it = v.begin();
    for(; it!= v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void leftView(node *root){
    if(root == NULL){
        return;
    }
    
    vector<int> v;
    int level = 1;

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();

        if(temp){
            v.push_back(temp->data);

            while(q.front() != NULL){

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }

                q.pop();
                temp = q.front();
            }
            q.push(NULL);
        }
        q.pop();
    }

    vector<int>::iterator it = v.begin();
    for(; it!= v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}


node* buildTree(){
    int data;
    cin>>data;

    queue<node*> q;
    node* root = NULL;
    while(data != -1){
        if(q.empty()){
            root = new node(data);
            q.push(root);
        }
        else{
            if(!q.empty()){
                node *temp = q.front();
                if(!temp->left){
                    temp->left = new node(data);
                    q.push(temp->left);
                }
                else{
                    temp->right = new node(data);
                    q.push(temp->right);
                    q.pop();
                }
            }
        }

        cin>>data;
    }
    return root;
}

void traversal(node *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}

int main(){
    node *root = buildTree();

    traversal(root);
    cout<<endl;

    bottomView(root);
    cout<<endl;

    topView(root);
    cout<<endl;

    verticalView(root);
    cout<<endl;
    
    rightView(root);
    cout<<endl;
    
    leftView(root);
    cout<<endl;
}
