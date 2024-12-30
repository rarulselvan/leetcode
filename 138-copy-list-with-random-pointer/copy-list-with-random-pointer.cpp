/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        // Map to store new nodes corresponding to
        // their original nodes
        unordered_map<Node*, Node*> mp;
        Node *curr = head;
    
        // Traverse original linked list to store new 
        // nodes corresponding to original linked list
        while (curr != NULL) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        
        // Loop to update the next and random pointers 
        // of new nodes 
        while (curr != NULL) {
            
            // Update the next pointer of new node
            mp[curr]->next = mp[curr->next];
        
            // Update the random pointer of new node
            mp[curr]->random = mp[curr->random];
        
            curr = curr->next;
        }
    
        // Return the head of the clone
        return mp[head];
     }
};