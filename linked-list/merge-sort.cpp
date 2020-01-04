/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* merge(ListNode *l1, ListNode *l2){
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }
    
    ListNode *ans=NULL, *temp=NULL;
    
    while(l1 && l2){
        if(l1->val <= l2->val){
            if(ans == NULL){
                ans = l1;
                temp = l1;
            }
            else{
                temp->next = l1;
                temp = temp->next;
            }
            l1 = l1->next;
        }
        else{
             if(ans == NULL){
                ans = l2;
                temp = l2;
            }
            else{
                temp->next = l2;
                temp = temp->next;
            }
            l2 = l2->next;
        }
    }
    
    if(l1){
        temp->next = l1;
    }
    if(l2){
        temp->next = l2;
    }
    
    return ans;
}
ListNode* Solution::sortList(ListNode* A) {
    if(A == NULL || A->next == NULL){
        return A;
    }
    
    ListNode *fst=A, *slw=A, *prev=NULL, *start=A;
    
    while(fst && fst->next){
        fst = fst->next->next;
        prev = slw;
        slw = slw->next;
    }
    
    prev->next = NULL;
    start = sortList(start);
    slw = sortList(slw);
    
    A = merge(start, slw);
    return A;
}
