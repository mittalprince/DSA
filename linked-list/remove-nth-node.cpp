/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {

    ListNode *fst = A, *slw = A;
    
    bool outside = false;
    for(int i=0; i<B; i++){
        if(fst->next){
            fst = fst->next;
        }
        else{
            outside = true;
            break;
        }
    }
    if(outside){
        ListNode* temp = A;
        A = A->next;
        delete temp;
        return A;
    }
    else{
        while(fst->next){
            fst = fst->next;
            slw = slw->next;
        }
        
        ListNode* t = slw->next;
        slw->next = slw->next->next;
        delete t;
        return A;
    }
}
/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

*/