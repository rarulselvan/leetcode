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
    int minDiffInBST(TreeNode* root) 
    {
        int ans=INT_MAX;
        TreeNode *prev=NULL;
        inorder(root, prev, ans);
        return ans;
    }
    // Function for in-order traversal of the tree 
    void inorder(TreeNode* curr, TreeNode *&prev, int& ans) 
    { 
        if (curr == NULL) 
            return; 
    
        // Calling in-order on the left sub-tree 
        inorder(curr->left, prev, ans); 
        if(prev)
            ans= min((curr->val-prev->val),ans);
        prev=curr;

        // Calling in-order on the right sub-tree 
        inorder(curr->right, prev, ans); 
    }
};