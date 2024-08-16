/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) 
{
    if(head==NULL)
        return NULL;
    struct ListNode* odd_head = head;
    struct ListNode* even_head = head->next;
    struct ListNode* odd = odd_head;
    struct ListNode* even = even_head;
    
    while( even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = even_head;
    
    return odd_head;
}