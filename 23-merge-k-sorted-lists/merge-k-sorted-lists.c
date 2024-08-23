/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode* mergeTwo(struct ListNode *a, struct ListNode *b) 
 {
    if (a==NULL)
    {
        printf("a is NULL");
        return b;
    }
    if (b==NULL)
    {
        printf("b is NULL");
        return a;
    }

    if (a->val <= b->val) 
    {
        a->next = mergeTwo(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeTwo(a, b->next);
        return b;
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int k) 
{
    // First merge two adjacent lists, then merge
    // the merged adjacen and so on.
    /*for (int gap = 1; gap < k; gap *= 2) 
    {
        for (int i = 0; i + gap < k; i += gap * 2)
        {
            lists[i] = mergeTwo(lists[i], lists[i + gap]);
        }
    }*/
    for(int i=1; i<k; i++)
        lists[0]=mergeTwo(lists[0], lists[i]);
    

    return k > 0 ? lists[0] : NULL;
}