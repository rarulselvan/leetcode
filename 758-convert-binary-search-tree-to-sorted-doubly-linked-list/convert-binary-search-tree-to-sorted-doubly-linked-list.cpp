/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution 
{
private :
    Node* prevNode;
    Node* listHead;
public:
    
        Node* treeToDoublyList(Node* root)
        {
            if (!root) return nullptr;   // If the tree is empty, return nullptr.

            // Reset the prevNode and listHead pointers before starting the DFS.
            prevNode = NULL;
            listHead = NULL;

            // Perform a depth-first search to traverse the tree in order.
            DFSInOrder(root);

            // After the DFS is done, connect the head and tail to make it circular.
            prevNode->right = listHead;
            listHead->left = prevNode;

            return listHead;    // Return the head of the doubly linked list.
         }

    void DFSInOrder(Node* root) 
    {
        if (!root)
            return;

        // Traverse the left subtree first (in-order traversal).
        DFSInOrder(root->left);

        // When processing the current node:
        if (prevNode) 
        {
            // If prevNode is not null, link it with the current node.
            prevNode->right = root;
            root->left = prevNode;
        } 
        else 
           listHead = root;    // If this is the leftmost node, it will be the head of the doubly linked list.
      
        prevNode = root;

        // Traverse the right subtree.
        DFSInOrder(root->right);
    }
};