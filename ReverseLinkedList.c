/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return head;
    if (head->next == NULL)
        return head;
    
    struct ListNode* NewHead = reverseList(head->next);
    struct ListNode* p1 = NewHead;
    
    while (p1->next != NULL)
        p1 = p1->next;
    
    p1->next = head;
    head->next = NULL;
    
    return NewHead;
    
}