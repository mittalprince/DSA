#include<iostream>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode * next;

    ListNode(int d){
        data = d;
        next = NULL;
    }
};

void printList(ListNode *root)
{
    if (root == NULL)
    {
        return;
    }

    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}


ListNode* ll_Reverse(ListNode* root, int k){
    if(root == NULL){
        return NULL;
    }
    ListNode* tail = root;

    ListNode *curr = root;
    ListNode *next = root;
    ListNode *prev = NULL;

    for(int i=0; i<k; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    if(curr!=NULL){
        tail->next = ll_Reverse(curr, k);
    }
    return prev;

}

ListNode* reverse(ListNode* head, int K){
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode *curr=head, *next=head, *prev=NULL, *start=NULL, *temp=NULL, *tail=NULL;
    int k = K;
    while(curr){
        temp = curr;
        k = K;
        prev = NULL;
        while(curr && k--){
            // cout<<"in "<<k<<endl;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // cout<<k<<endl;
        if(k && !curr){
            // cout<<"out"<<k;
            curr=prev, next=prev, prev=NULL;
            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
        }
        if(start == NULL){
            start = prev;
        }
        
        if(tail){
            tail->next = prev;
        }
        tail = temp;
    }

    return start;
}

int main(){

    ListNode* root = NULL, *tail = NULL;
    int n, temp, k;
    cin>>n>>k;
    cin>>temp;
    root = tail = new ListNode(temp);

    for(int i=1; i<n; i++){
        cin>>temp;
        ListNode* t = new ListNode(temp);
        tail->next = t;
        tail = t;
    }

    // root = ll_Reverse(root, k);
    root = reverse(root, k);
    printList(root);

    return 0;
}
