/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head==NULL)
        return head;
    if (n<0)
        return head;
    struct ListNode* pp1, *p1, *lastNode;
    
    int i=1;
    p1=head;
    lastNode=head;
    while ((i<n) && (lastNode!= NULL)){
        lastNode=lastNode->next;
        i++;
    }
    
    if (i<n)
        return head;
    
    if (lastNode->next==NULL){
        p1=head->next;
        free(head);
        return p1;
    }
    
    pp1=head;
    p1=p1->next;
    lastNode=lastNode->next;
    while (lastNode->next!=NULL){
        lastNode=lastNode->next;
        p1=p1->next;
        pp1=pp1->next;
    }
    pp1->next=p1->next;
    free(p1);
    return head;
}