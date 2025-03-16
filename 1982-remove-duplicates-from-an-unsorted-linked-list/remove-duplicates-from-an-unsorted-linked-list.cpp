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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) 
    {
        ListNode* tempHead=head;
        unordered_map<int, int> Map;

        if(head==NULL)
            return NULL;
        
        while(tempHead)
        {
            Map[tempHead->val]++;
            tempHead=tempHead->next;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* current = head;

        while(current)
        {
            if(Map[current->val]>1)
                prev->next=current->next;//skip the current node
            else             
                prev = current; // Move prev forward only if node is retained

            current = current->next;
        }
        return dummy->next;
    }
};