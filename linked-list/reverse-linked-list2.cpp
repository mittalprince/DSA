/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(A == NULL || A->next == NULL){
        return A;
    }
    
    int m = B;
    ListNode *prev_of_start=NULL, *start=A;
    B = B-1;
    while(B--){
        prev_of_start = start;
        start = start->next;
    }
    
    C = C-m+1;
    ListNode *curr=start, *next=start, *prev=NULL, *temp=start;
    while(C-- && curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    if(prev_of_start){
        prev_of_start->next = prev;
    }
    
    if(m == 1){
        A = prev;
    }
    temp->next = curr;
    
    return A;
}


/* 


Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 

*/