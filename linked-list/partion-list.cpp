#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d):data(d),next(NULL){}
};

void printList(node *head){
    if(head == NULL){
        return;
    }
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

node* partionList(node *head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node *lt=NULL, *eq=NULL, *gt=NULL, *curr=head, *prev=NULL;
    node *temp1=NULL, *temp2=NULL, *temp3=NULL;

    while(curr){
        if(prev){
            prev->next = NULL;
        }
        if(curr->data < k){
            if(lt == NULL){
                lt = curr;
                temp1 = lt;
            }
            else{
                temp1->next = curr;
                temp1 = temp1->next;
            }
        }
        else if(curr->data == k){
            if(eq == NULL){
                eq = curr;
                temp2 = eq;
            }
            else{
                temp2->next = curr;
                temp2 = temp2->next;
            }
        }
        else{
            if(gt == NULL){
                gt = curr;
                temp3 = gt;
            }
            else{
                temp3->next = curr;
                temp3 = temp3->next;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    
    // printList(lt);
    // printList(eq);
    // printList(gt);

    node *ans = NULL;
    if(lt == NULL){
        if(eq == NULL){
            ans = gt;
        }
        else{
            ans = eq;
            temp2->next = gt;
        }
    }
    else{
        ans = lt;
        if(eq == NULL){
            temp1->next = gt;
        }
        else{
            temp1->next = eq;
            temp2->next = gt;
        }
    }

    return ans;
}

int main(){
    int n,temp,k;
    cin>>n>>k;
    node *root, *tail=NULL;
    while(n--){
        cin>>temp;
        if(tail == NULL){
            root = tail = new node(temp);
        }
        else{
            tail->next = new node(temp);
            tail = tail->next;
        }
    }

    root = partionList(root, k);
    printList(root);
}