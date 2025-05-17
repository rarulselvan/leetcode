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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* fast = head;

        while (--k)
            fast = fast->next;
        // At this point, fast points to the kth node from the beginning
        
        ListNode* slow = head; // This will point to the kth node from the end
        ListNode* firstNode = fast; // save it

        while (fast->next) 
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* secondNode = slow; // Keep reference to the kth node from the end
        swap(firstNode->val, secondNode->val);

        return head;
    }
};