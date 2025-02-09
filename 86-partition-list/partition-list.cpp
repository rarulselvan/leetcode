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
    ListNode* partition(ListNode* head, int x) 
    {
        //Create tow dummy nodes
        ListNode* l = new ListNode();
        ListNode* r = new ListNode();

        ListNode* tl = l;
        ListNode* tr = r;
        //for (; head; head = head->next) 
        while (head)
        {
            if (head->val < x) 
            {
                tl->next = head;
                tl = tl->next;
            } 
            else
            {
                tr->next = head;
                tr = tr->next;
            }
            head=head->next;
        }
        tr->next = nullptr;
        tl->next = r->next;
        //try to free the memory of l & r here
        return l->next;
    }
};