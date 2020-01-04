/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A == NULL || A->next == NULL){
        return A;
    }
    
    ListNode *start = new ListNode(0);
    start->next = A;
    ListNode *curr = start;
    ListNode *temp;
    
    while(curr->next){
        temp = curr->next;
        while(temp->next && temp->val ==temp->next->val){
            temp = temp->next;
        }
        
        if(curr->next == temp){
            curr = curr->next;
        }
        else{
            curr->next = temp->next;
        }
    }
    
    return start->next;
    // -------------------------------------------
    
    // if(A == NULL || A->next == NULL){
    //     return A;
    // }
    
    // ListNode *curr=A, *temp=A, *start=A, *prev=NULL;
    
    // while(curr){
    //     while(curr->next && curr->val == curr->next->val){
    //         curr = curr->next;
    //     }
        
    //     if(curr != temp){
    //         if(start == temp){
    //             start = curr->next;
    //             temp = curr->next;
    //         }
    //         else{
    //             prev->next = curr->next;
    //             temp = prev->next;
    //         }
    //     }
    //     else{
    //         prev = temp;
    //         temp = curr->next;
    //     }
        
    //     curr = curr->next;
    // }
    
    // return start;
    
    
    // ------------------------------------------------
    // map<int, int>m;
    // ListNode* temp = A, *head = NULL,  *tail = NULL;
    
    // while(temp != NULL){
    //     m[temp->val]++;
    // }
    
    // for(auto it=m.begin(); it != m.end(); it++){
    //     if(it->second == 1){
    //         if(tail == NULL){
    //             head = tail = new ListNode(it->first);
    //         }
    //         else{
    //             tail->next = new ListNode(it->first);
    //             tail = tail->next;
    //         }
    //     }
    // }
    
    // A = head;
    // return A;
}



/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/