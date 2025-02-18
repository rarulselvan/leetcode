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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        //Lamda function
        auto compare = [](ListNode* a, ListNode* b)
                        {return a->val > b->val; };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)>minHeap(compare);
       
        //priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Push the head of each non-empty list into the heap
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        // Dummy node to simplify handling of result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!minHeap.empty()) 
        {
            // Extract the smallest element
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            
            // Attach it to the result list
            tail->next = minNode;
            tail = minNode;//tail->next;

            // Push the next node from the extracted list into the heap
            if (minNode->next) 
                minHeap.push(minNode->next);
        }

        return dummy->next; // The actual head of the merged list
    }
};