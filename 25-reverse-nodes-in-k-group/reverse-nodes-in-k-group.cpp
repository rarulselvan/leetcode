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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head ==NULL)
            return head;
        
        struct ListNode *prev=NULL;
        struct ListNode *current=head;
        struct ListNode *next=NULL;
        unsigned int count=k;
        unsigned int rcount=0;

        struct ListNode *temp=head;
        while(temp)
        {
            temp=temp->next;
            rcount++;
        }
        if(rcount <count)
            return head;

        while(current && count)
        {   
            next=current->next;
            current->next=prev;
            prev=current;	
            current=next;
            count--;
        }

        head->next=reverseKGroup(next, k);
    
        return prev;
    }
};
