/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
 bool hasCycle(ListNode *head) 
    {
        if (head == NULL)  
            return false;

        ListNode *slowPointer = head;
        ListNode *fastPointer = head;

        while (fastPointer)  // Fix: Ensure next node exists
        {
            
            {
                slowPointer = slowPointer->next;
                if(fastPointer->next)
                    fastPointer = fastPointer->next->next;
                else
                    return false;

                if (slowPointer == fastPointer)  // Cycle detected
                    return true;
            }
        }
        return false;  // No cycle found
    }
};