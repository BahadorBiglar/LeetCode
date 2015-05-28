/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *second;
    if (head==NULL)
        return head;
    if (head->next==NULL)
        return head;
    second = head->next;
    int temp = head->val;
    head->val = second->val;
    second->val = temp;
    swapPairs(second->next);
    return head;
}