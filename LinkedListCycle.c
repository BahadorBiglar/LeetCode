/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
        if (head == NULL)
        return false;
    
    struct ListNode *p[10000], *curr;
    curr=head;
    
    for (int i=0; curr!=NULL; i++){
        for (int j=0; j<i; j++)
            if (p[j]==curr)
                return true;
        p[i]=curr;
        curr=curr->next;
    }
    return false;
}