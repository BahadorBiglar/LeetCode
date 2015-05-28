/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head==NULL)
        return NULL;
    
    struct ListNode *p, *n;
    while ((head != NULL) && (head->val) == val){
        p=head->next;
        free(head);
        head=p;
    }
    if (head==NULL)
        return NULL;

    p=head;
    n=head->next;
    while ((n!=NULL)){
        if (n->val != val){
            p=n;
            n=n->next;
        }
        else{
            p->next = n->next;
            free(n);
            n=p->next;
        }
    }
    
    return head;
}