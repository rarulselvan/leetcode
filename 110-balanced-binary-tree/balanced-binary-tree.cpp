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
    bool isBalanced(TreeNode* root) 
    {
        // If tree is empty it is height balanced
        if (root == NULL)
            return true;

        int lHeight = height(root->left);
        int rHeight = height(root->right);
        
        // If absolute height difference is greater than 1... then return false no need to explore the left and right sub trees
        if (abs(lHeight - rHeight) > 1)
            return false;
        //This levle is balanced...explore left and right sub trees 
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        else
           return  1+max(height(root->left), height(root->right));
    }
};