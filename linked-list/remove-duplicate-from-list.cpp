ListNode* Solution::deleteDuplicates(ListNode* A) {

    if(A == NULL || A->next ==NULL){
        return A;
    }
    
    ListNode *curr=A, *start=A, *temp=NULL;
    
    while(curr){
        temp = curr;
        while(temp->next && temp->val == temp->next->val){
            temp = temp->next;
        }
        
        curr->next = temp->next;
        curr = curr->next;
    }
    return start;
    
    // map<int, int>m;
    // ListNode* temp = A;
    // ListNode* prev = A;
    // while(temp != NULL){
    //     if(m.find(temp->val) == m.end()){
    //         m[temp->val]++;
    //         prev = temp;
    //         temp = temp->next;
    //     }
    //     else{
    //         ListNode *t = temp;
    //         if(temp->next){
    //             prev->next = temp->next;
    //             temp = temp->next;
    //         }
    //         else{
    //             prev->next = NULL;
    //             temp = NULL;
    //         }
    //         delete t;
    //     }
    // }
    
    // return A;
}