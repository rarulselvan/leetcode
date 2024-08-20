/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k)
 {
    if (head == NULL || head->next == NULL || k == 0) return head;
    
    // calculating length
    struct ListNode* temp = head;
    int length = 1;
    while (temp->next != NULL)
    {
        ++length;
        temp = temp->next;
    }
    
    // link last node to first node
    temp->next = head;
    k = k % length; // when k is more than length of list
    int end = length - k; // to get end of the list
    while (end != 0)
    {
        temp = temp->next;
        end--;
    }
    
    // breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
    
    return head;
}