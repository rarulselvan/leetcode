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
class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        int val=0;
        return treePathsSum(root, val);
    }
    int treePathsSum(TreeNode* root, int val) 
    {
        cout << val<<" ";
        if (root == NULL) 
            return 0;
        
        // Update value
        val = val*10+root->val;
        
        // If node is leaf node, nothing required return the value.
        if (root->left==NULL && root->right==NULL)
            return val;
            
        return treePathsSum(root->left, val) +
                treePathsSum(root->right, val);
    }
};