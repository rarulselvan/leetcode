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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if (t1 == nullptr)
            return t2;
        if (t2 == nullptr)
            return t1;

        t1->val = t1->val+t2->val;
        
        // recur on left subtree and update the left child of first node.
        t1->left = mergeTrees(t1->left, t2->left);
    
        // recur on right subtree and update the right child of first node.
        t1->right = mergeTrees(t1->right, t2->right);
        
        // return merged tree.
        return t1;
    }
};