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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* dummy = new ListNode(0);  // Dummy node
        dummy->next = head;
        ListNode* prev = dummy;

        while (head) 
        {
            // If current node has duplicates, skip all occurrences
            if (head->next && head->val == head->next->val) 
            {
                while (head->next && head->val == head->next->val) 
                {
                    head = head->next;
                }
                prev->next = head->next;  // Remove duplicates
            } 
            else 
                prev = prev->next;  // Move prev only if no duplicates
            
            head = head->next;  // Move to next node
        }
        
        //free the memory of dummy node
        ListNode *temp=dummy->next;
        delete dummy;

        return temp;
    }
};