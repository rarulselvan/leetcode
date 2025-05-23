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
        if(maxHeightDifference(root)==INT_MAX)
            return false;
        else
            return true;
    }
    int maxHeightDifference(TreeNode* root)
    {
        if(!root)
            return 0;
        int leftHeight=maxHeightDifference(root->left);
        int rightHeight=maxHeightDifference(root->right);

        if (leftHeight == INT_MAX || rightHeight == INT_MAX || abs(leftHeight - rightHeight) > 1) 
            return INT_MAX;

        return 1+max(leftHeight,rightHeight);
    }
};