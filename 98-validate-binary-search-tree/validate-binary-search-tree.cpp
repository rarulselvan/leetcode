/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    bool isBST(struct TreeNode* root,struct TreeNode* &prev)
    {
       if (root)
        {
            if (!isBST(root->left, prev)) // Check left subtree
                return false;

            if (prev && prev->val >= root->val) // BST violation condition
                return false;
            
            prev = root; // Update prev after visiting node

            return isBST(root->right, prev); // Check right subtree
        }
        return true;
    }

    bool isValidBST(struct TreeNode* root) 
    {
        struct TreeNode* prev=NULL;
        return isBST(root, prev);  
    }
};
