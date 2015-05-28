/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL)
        return head;
    
    struct ListNode *father, *son, *beforeStart = NULL, *start = head, *newHead = head;

    while ((start->next != NULL) && (start->val<x)){
        beforeStart = start;
        start = start->next;
    }
    
    if (start->next==NULL)
        return head;
    
    son    = start;
    father = start->next;
    while (father != NULL){
        if (father->val<x){
            son->next=father->next;
            father->next=start;
            if (beforeStart != NULL){
                beforeStart->next = father;
                beforeStart = father;
            }
            else{
                beforeStart = father;
                newHead     = beforeStart;
            }
            father=son->next;
        }
        else{
            father = father->next;
            son    = son->next;
        }
    }
    
    return newHead;
}