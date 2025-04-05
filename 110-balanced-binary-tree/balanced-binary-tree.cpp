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
        int ans = findMaxHeight(root);
        if(ans ==-1)
            return false;
        else
            return true;
        
    }
    //Find the max height of the tree...in that process if abs(leftHeight -RightHeight) is more than 1...it isconculuded theat thre tree is unbalnce and return -1
    int findMaxHeight(TreeNode* root)
    {
        if (!root)
            return 0;
        
        int leftHeight = findMaxHeight(root->left);
        int rightHeight = findMaxHeight(root->right);

            if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) 
            {
                // If the left or right subtree is unbalanced, or if the current subtree
                // is unbalanced (difference in height > 1), return -1 as an indicator.
                return -1;
            }

        return 1 + max(leftHeight, rightHeight);
    }
};