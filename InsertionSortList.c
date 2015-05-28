/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL)
        return head;
    
    struct ListNode *last = head, *newNode, *pos;
    
    while (last->next){
        if (last->val<=last->next->val){
            last=last->next;
        }
        else if ((head->val)>(last->next->val)){
            newNode = last->next;
            last->next = newNode->next;
            newNode->next=head;
            head=newNode;
        }
        else{
            newNode = last->next;
            last->next = newNode->next;
            pos = head;
            while (pos->next->val<newNode->val)
                pos=pos->next;
            newNode->next=pos->next;
            pos->next = newNode;
        }
    }
    return head;
}