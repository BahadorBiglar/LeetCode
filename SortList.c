/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeList(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode *p1 = head1, *p2 = head2, *newHead, *p3;
    
    newHead = (struct ListNode *) malloc (sizeof(struct ListNode));
    p3 = newHead;
    
    while ((p1) && (p2)){
        if (p1->val < p2->val){
            p3->next = p1;
            p1=p1->next;
        }
        else{
            p3->next = p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    p3->next = (p1!=NULL) ? p1:p2;
    
    p3 = newHead->next;
    free(newHead);
    return p3;
}

struct ListNode* sortList(struct ListNode* head) {
    if ((head == NULL) || (head->next == NULL))
        return head;
    
    struct ListNode *walker = head;
    struct ListNode *runner = head;
    
    while (runner->next){
        runner = runner->next;
        if (!(runner->next))
            break;
        runner = runner->next;
        walker = walker->next;
    }
    
    struct ListNode* head2 = walker->next;
    walker->next = NULL;
    
    head  = sortList(head);
    head2 = sortList(head2);
    
    return mergeList(head, head2);
}