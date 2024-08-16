/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) 
{
    struct ListNode* temp=NULL;
    if(node)
    {
        node->val=node->next->val;
        temp=node->next;
        node->next=node->next->next;
        free(temp);
    }
}