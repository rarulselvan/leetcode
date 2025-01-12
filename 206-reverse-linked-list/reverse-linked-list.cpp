/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (head == NULL || head->next == NULL)
            return head;

        // Reverse the rest of the list
        ListNode* revHead = reverseList(head->next);
        
        // Make the current head the last node
        head->next->next = head;
        
        // Update the next of current head to NULL
        head->next = nullptr;
        
        // Return the new head of the reversed list
        return revHead;
}
};

