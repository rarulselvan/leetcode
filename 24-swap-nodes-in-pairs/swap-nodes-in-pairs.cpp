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
    ListNode* swapPairs(ListNode* head) 
    {
        // If the list has no node or has only one node left.
        if ((head == NULL) || (head->next == NULL)) 
            return head;
        
        // Get the two nodes to be swapped..let us call as firstNode and secondNode
        ListNode* firstNode = head;
        ListNode* secondNode = head->next; //return the second node
        // Swapping
        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;
        // Now the head is the second node
        return secondNode;
    }
};