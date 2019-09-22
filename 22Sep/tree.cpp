#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;

    Node(int d):data(d),right(NULL),left(NULL){}
};

class Pair{
    public:
    int height, dia;
};

class pairM{
    public:
    bool balanced;
    int height;
};

pairM isbalanced(Node* root){
    pairM p;
    if(root == NULL){
        p.balanced = true;
        p.height = 0;
        return p;
    }

    pairM L,R;
    L = isbalanced(root->left);
    R = isbalanced(root->right);
    p.height = max(L.height, R.height)+1;

    if(abs(L.height-R.height) <= 1 && L.balanced && R.balanced){
        p.balanced = true;
    }
    p.balanced = false;
    return p;
}

Pair OptDia(Node* root){
    Pair p;
    if(root == NULL){
        p.height = p.dia = 0;
        return p;
    }

    Pair l,r;
    l = OptDia(root->left);
    r = OptDia(root->right);

    p.height = max(l.height, r.height)+1;
    int opt1 = l.height + r.height;
    int opt2 = max(l.dia, r.dia);
    p.dia = max(opt2, opt1);
    return p;

}

Node* insert(Node* root){
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);
    root->left = insert(root->left);
    root->right = insert(root->right);

    return root;
}

void printPre(Node* root){
    if(root == NULL){
        return;
    }
    
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int x = height(root->left);
    int y = height(root->right);

    return max(x,y)+1;
}


int sumNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int x = sumNodes(root->left);
    int y = sumNodes(root->right);

    return root->data+x+y;
}

int replaceBySum(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int temp = root->data;
    root->data = replaceBySum(root->left)+replaceBySum(root->right);
    return root->data+temp;
}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int opt1 = height(root->left)+height(root->right);
    int opt2 = max(diameter(root->left), diameter(root->right));
    return max(opt1, opt2); 
}   

void LOT(Node* root, int k){
    if(root == NULL){
        return;
    }

    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    LOT(root->left, k-1);
    LOT(root->right, k - 1);
}

void levelWise(Node* root){
    if(root == NULL){
        return;
    }
    int h = height(root);
    for(int i=1; i<=h ; i++){
        LOT(root, i);
        cout<<endl;
    }
}
void BFS(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    
}

int main(){
    Node* root = NULL;
    root = insert(root);
    printPre(root);
    cout<<endl;
    cout<<height(root)<<endl;
    // cout<<sumNodes(root)<<endl;
    // int sum = replaceBySum(root);
    // cout<<sum<<endl;
    // printPre(root);
    LOT(root, 2);
    cout << endl;
    levelWise(root);
    cout<<endl;
    BFS(root);
    cout<<endl;
}