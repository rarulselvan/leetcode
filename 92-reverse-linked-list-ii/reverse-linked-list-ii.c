/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseN(struct ListNode* head, int n) 
{
    if (n == 1)
        return head;

    struct ListNode* newHead = reverseN(head->next, n - 1);
    struct ListNode* headNext = head->next;
    head->next = headNext->next;
    headNext->next = head;

    return newHead;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) 
{
    if (left == 1)
        return reverseN(head, right);

    head->next = reverseBetween(head->next, left - 1, right - 1);//head is moving hence left and right will reduce by one

    return head;
}