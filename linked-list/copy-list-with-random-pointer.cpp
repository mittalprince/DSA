/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == NULL)
        {
            return head;
        }

        Node *curr = head;

        while (curr)
        {
            Node *temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }

        Node *ans = head->next;
        curr = head;

        while (curr)
        {
            Node *temp = curr->next;

            if (curr->random)
            {
                temp->random = curr->random->next;
            }

            curr = temp->next;
        }

        curr = head;
        while (curr)
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            curr = curr->next;

            if (curr)
            {
                temp->next = curr->next;
            }
        }

        return ans;
    }
};