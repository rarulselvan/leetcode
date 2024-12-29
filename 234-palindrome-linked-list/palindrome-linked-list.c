/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
    struct ListNode* findMid(struct ListNode* head)
    {
        struct ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            //if(fast) fast=fast->next;
        }
        return slow;
    }
    struct ListNode* reverseList(struct ListNode* head)
    {
        struct ListNode* prev=NULL,*curr=head,*temp=NULL;
        while(curr != NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool compareList(struct ListNode* head1, struct ListNode* head2)
    {
        while(head1!=NULL && head2!=NULL){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(struct ListNode* head) 
    {
        if(head==NULL || head->next==NULL) return true;
        struct ListNode* h=head;
        struct ListNode* mid = findMid(h);
        struct ListNode* h2=reverseList(mid);
        return compareList(head,h2);
    }