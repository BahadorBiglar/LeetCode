/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;

        int newVal, cr = 0;
        bool is_first = true;
        ListNode *head, *prev, *l3;

        while ((l1) || (l2)){
            newVal = cr;
            newVal = newVal + ((l1==NULL) ? 0:(l1->val));
            newVal = newVal + ((l2==NULL) ? 0:(l2->val));
            cr = newVal / 10;
            newVal = newVal % 10;
            
            l3 = new ListNode(newVal);
            if (is_first){
                head = l3;
                prev = head;
                is_first = false;
            }
            else{
                prev->next = l3;
                prev = l3;
            }
            if (l1!=NULL) l1 = l1->next;
            if (l2!=NULL) l2 = l2->next;
        }
        if (cr == 1){
            l3 = new ListNode(cr);
            prev->next = l3;
        }
        
        return head;
    }
};