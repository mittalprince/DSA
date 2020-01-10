#include<iostream>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int d){
        data = d;
        next = NULL;
    }
};

void printList(ListNode* head){
    if(head == NULL){
        return;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

ListNode* merge(ListNode *&root1, ListNode *&root2){

    ListNode *temp = NULL;
    ListNode* ans;
    if(root1->data <= root2->data){
        temp = root1;
        ans = root1;
        root1 = root1->next;
    }
    else{
        temp = root2;
        ans = root2;
        root2 = root2->next;
    }
    while(root1 && root2){
        if(root1->data <= root2->data){
            temp->next = root1;
            temp = temp->next;
            root1 = root1->next;
        }
        else{
            temp->next = root2;
            temp = temp->next;
            root2 = root2->next;
        }
    }

    if(root1){
        temp->next = root1;
    }
    if(root2){
        temp->next = root2;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,temp;
        cin>>n;
        ListNode* root = NULL, *tail;
        if(n>0){
            cin>>temp;
            root = tail = new ListNode(temp);
            for(int i=1; i<n; i++){
                cin>>temp;
                tail->next = new ListNode(temp);
                tail = tail->next;
            }
            printList(root);
        }
        
        ListNode* root2 = NULL, *tail2;
        cin>>m;
        if(m>0){
            cin>>temp;
            root2 = tail2 = new ListNode(temp);
            for(int i=1; i<m; i++){
                cin>>temp;
                tail2->next = new ListNode(temp);
                tail2 = tail2->next;
            }
            printList(root2);
        }
        if(root && root2){
            root = merge(root, root2);   
        }
        else{
            root = (root == NULL? root2 : root);
        }
        printList(root);
    }
}