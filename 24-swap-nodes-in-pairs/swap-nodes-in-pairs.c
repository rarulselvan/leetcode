/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* swapPairsK(struct ListNode* root, int k)
{
  	struct ListNode *prev=NULL;
	struct ListNode *current=root;
	struct ListNode *next=NULL;

	int count=k;

	if(root==NULL)
		return NULL;

    struct ListNode *temp=root;
    int rcount=0;
    while(temp)
    {
        temp=temp->next;
        rcount++;
    }
    if(rcount <count)
        return root;


	while(current && count>0)
	{
		next=current->next;
		current->next=prev;
		prev=current;	
		current=next;
		count--;
	}
	//if(next!=NULL)
		root->next = swapPairsK(next, k);//if k is three... 123 456 --> 321 654....1 should point to next reverse....4 should point to next reverse...so root->next
	
	return prev;// this is the new head
}

struct ListNode* swapPairs(struct ListNode* head) {
   return swapPairsK(head, 2);//k=2
}