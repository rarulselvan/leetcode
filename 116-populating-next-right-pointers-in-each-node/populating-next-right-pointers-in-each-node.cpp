/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution 
{
public:

    Node* connect(Node* root) 
    {
        if (!root)
            return root;

        queue<Node*> q;
        q.push(root);

        // Process nodes level by level.
        while (!q.empty()) 
        {
            Node* prevNode = NULL;

            int levelNodeCount = q.size();

            // Iterate over all nodes in the current level.
            for (int i = q.size(); i; i--)
            {
                Node* currentNode = q.front();
                q.pop();

                // Connect the previous node with the current node.
                if (prevNode)   
                    prevNode->next=currentNode;
                
                prevNode = currentNode;

                if (currentNode->left)
                    q.push(currentNode->left);
                
                // Add the right child to the queue if it exists.
                if (currentNode->right) 
                    q.push(currentNode->right);
            }
        }
        return root;
    }
};