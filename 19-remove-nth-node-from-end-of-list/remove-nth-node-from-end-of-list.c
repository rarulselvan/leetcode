/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode *slow=head;
    struct ListNode *fast=head;
    struct ListNode *temp=NULL;

    while(n>0)
    {
        n--;
        fast=fast->next;
    }
    
    if(fast==NULL)
    {
        temp=slow->next;
        free(slow);
        return temp;
    }
    while(fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    temp=slow->next;
    slow->next=slow->next->next;
    free(temp);
    return head;
}