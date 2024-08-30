/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head)
 {
    if(head==NULL)
        return NULL;
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    struct ListNode* preSlow=NULL;

    while(fast && fast->next)
    {
        preSlow=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(preSlow)
        preSlow->next=slow->next;
    else
        head=NULL;
    return head;
}