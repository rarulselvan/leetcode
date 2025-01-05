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

class Solution {

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

    // Helper DFS function to perform in-order traversal.
    void DFSInOrder(Node* currentNode) {
        if (!currentNode) return;  // Base case: if the current node is null, just return.

        // Traverse the left subtree first (in-order traversal).
        DFSInOrder(currentNode->left);

        // When processing the current node:
        if (prevNode) {
            // If prevNode is not null, link it with the current node.
            prevNode->right = currentNode;
            currentNode->left = prevNode;
        } else {
            // If this is the leftmost node, it will be the head of the doubly linked list.
            listHead = currentNode;
        }
      
        // Move prevNode to the current node before traversing the right subtree.
        prevNode = currentNode;

        // Traverse the right subtree.
        DFSInOrder(currentNode->right);
    }
};