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
    int count=0;
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        if (root == nullptr) return -1;
        
        // Process left subtree.
        int left = kthSmallest(root->left, k);
        
        // If kth smallest is found in left 
        // subtree, then return it.
        if (left != -1) return left;
        
        // increment node count
        count++;
        
        // If curr node is kth smallest,
        // return it.
        if (k==count) return root->val;
        
        // Else process the right subtree
        // and return its value.
        int right = kthSmallest(root->right, k);
        return right;
    }
};