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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0;
        ListNode* current = NULL;
        ListNode* retNode = NULL;

        while(l1 || l2 || carry)  
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            cout << sum%10<< " ";
            //if(sum/10)
            //    cout <<sum/10<<" ";

            carry = sum / 10;
            if(!current)
            {
                current = new ListNode(sum % 10);
                retNode=current;
            }
            else
            {  
                current->next=new ListNode(sum % 10); 
                current=current->next;
            }          
                
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return retNode;
    }
};