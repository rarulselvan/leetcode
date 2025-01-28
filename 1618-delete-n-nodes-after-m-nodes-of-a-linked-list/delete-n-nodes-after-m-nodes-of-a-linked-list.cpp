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
    ListNode* deleteNodes(ListNode* head, int m, int n)
    {
        if(head==NULL)
            return head;
 
        ListNode *oriHead=head;
        while(head)
        {
            int mcount=m;
            int ncount=n;
            ListNode *tmphead=NULL;
            while(mcount && head)
            {
                tmphead=head;
                head=head->next;
                mcount--;
            }
            if(head)
            {   
                while(ncount && head)
                {
                    head=head->next;
                    ncount--;
                    //TBD free the nodes here
                }
                tmphead->next=head;
            }
        }
        return oriHead;
        
    }
};