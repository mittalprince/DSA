/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    
    if(A == NULL || A->next == NULL || A->next->next == NULL){
        return A;
    }
    
    ListNode *fst=A, *mid=A, *prev_of_mid=NULL;
    
    while(fst && fst->next){
        fst = fst->next->next;
        prev_of_mid = mid;
        mid = mid->next;
    }
    
    prev_of_mid->next = NULL;
    
    ListNode *curr=mid, *next=mid, *prev=NULL;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    ListNode *start1=A, *start2=prev, *temp1, *temp2, *holder=NULL;
    
    while(start1 && start2){
        temp1 = start1->next;
        start1->next = start2;
        temp2 = start2->next;
        start2->next = temp1;
        holder = start2;
        start2 = temp2;
        start1 = temp1;
    }
    
    if(start2){
        holder->next = start2;
        start2->next = NULL;
    }
    return A;
}

/* 


Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*/