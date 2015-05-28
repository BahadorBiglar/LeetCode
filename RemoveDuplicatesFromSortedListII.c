/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p1, *n1, *nn1, *temp;
    
    while(true){
        p1=head;
        if (p1==NULL)
            return head;
        
        n1=p1->next;
        if (n1==NULL)
            return head;
        if ((n1!=NULL) && ((p1->val) == (n1->val))){
            while ((n1!=NULL) && ((p1->val) == (n1->val))){
                n1=n1->next;
                free(p1->next);
                p1->next=n1;
            }
            free (head);
            head = n1;
        }
        else
            break;
    }
    
    nn1=n1->next;
    while (nn1){
        if ((n1->val) == (nn1->val)){
            while ((nn1) && ((n1->val) == (nn1->val)))
                nn1=nn1->next;
            
            p1->next = nn1;
            while ((n1) != (nn1)){
                temp = n1->next;
                free(n1);
                n1=temp;
            }
            if (n1)
                nn1=n1->next;
        }
        else{
            p1 = n1;
            n1 = nn1;
            nn1= n1->next;
        }
    }
    
    return head;
}