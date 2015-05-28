/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p1=head, *n1;
    if (p1==NULL)
        return head;
    
    n1=p1->next;
    while (n1){
        if ((p1->val) == (n1->val)){
            n1=n1->next;
            free(p1->next);
            p1->next=n1;
        }
        else{
            p1 = n1;
            n1 = n1->next;
        }
        
    }
    
    return head;
}