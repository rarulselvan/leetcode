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
      ListNode* successor = nullptr; // To store the (n+1)th node
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left==right)
            return head;
        if(left==1)//starting node
            return reverseN(head, right);

        head->next = reverseBetween(head->next, left - 1, right - 1);//head is moving hence left "position" and right "position" will reduce by one

        return head;
    }
   ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) 
        { // Base case: Stop at nth node
            successor = head->next; // Store (n+1)th node
            return head;
        }

        ListNode* newHead = reverseN(head->next, n - 1);
        
        head->next->next = head;
        head->next = successor; // Connect the last node of reversed part to remaining list...this will go all the to the original recursive caller
        return newHead;
    }
};