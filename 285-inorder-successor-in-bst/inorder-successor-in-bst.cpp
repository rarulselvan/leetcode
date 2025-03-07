/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        if(root==NULL)
            return root;
        if(p->val < root->val)
        {
            TreeNode* leftSuccessor = inorderSuccessor(root->left, p);
            if(leftSuccessor)
                return leftSuccessor;
            else
                return root;
        }
        else
        {
            TreeNode* rightSuccessor = inorderSuccessor(root->right, p);
            return rightSuccessor;
        }
    }
};
