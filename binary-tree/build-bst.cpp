#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d), left(NULL), right(NULL){}
};

class listnode{
    public:
    int data;
    listnode* next;

    listnode(int d):data(d),next(NULL){}
};

int len(listnode *head){
    if(head == NULL){
        return 0;
    }
    int len = 0;
    listnode *temp= head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void printList(listnode *head){
    if (head == NULL)
    {
        return;
    }
    listnode *temp = head;
    while (temp)
    {
       cout<<temp->data<<"->";
        temp = temp->next;
    }
}

// from Sorted Linked List

node* buildLLTree(listnode *&head, int n){
    if(n <= 0){
        return NULL;
    }
    node *left = buildLLTree(head, n/2);
    node *root = new node(head->data);
    root->left = left;
    head = head->next;

    node *right = buildLLTree(head, n-(n/2)-1);
    root->right = right;

    return root;
}

void fromLL(){
    listnode *head, *tail = NULL;
    int data, n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>data;
        if(tail == NULL){
            head = tail = new listnode(data);
        }
        else{
            tail->next = new listnode(data);
            tail = tail->next;
        }
    }
    printList(head);
    cout<<endl;
    node *root = buildLLTree(head, n);
    preOrder(root);
    cout<<endl;
}


// from Sorted Array 

node* buildTree(int arr[], int s, int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)>>1;
    node *root = new node(arr[mid]);
    root->left = buildTree(arr, s, mid-1);
    root->right = buildTree(arr, mid+1, e);

    return root;
}

void fromArr(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        node *root = buildTree(arr, 0, n - 1);
        preOrder(root);
        cout << endl;
    }
}

int main(){

    fromLL();
    return 0;
}