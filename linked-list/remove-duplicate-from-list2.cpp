/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    map<int, int>m;
    ListNode* temp = A, *head = NULL,  *tail = NULL;
    
    while(temp != NULL){
        m[temp->val]++;
    }
    
    for(auto it=m.begin(); it != m.end(); it++){
        if(it->second == 1){
            if(tail == NULL){
                head = tail = new ListNode(it->first);
            }
            else{
                tail->next = new ListNode(it->first);
                tail = tail->next;
            }
        }
    }
    
    A = head;
    return A;
}


/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/