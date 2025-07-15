/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) 
    {
        Node *first=p;
        Node *second=q;

        while(first != second)
        {
            first= first->parent? first->parent:q;
            second= second->parent? second->parent:p;
        }
        return first;
    }
};
