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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        findLowestCommonAncestor(root, p, q);
        return ancestor;
    }

private:
    TreeNode* ancestor = NULL;

    bool findLowestCommonAncestor(TreeNode* root, TreeNode* nodeP, TreeNode* nodeQ) 
    {
        if (!root) 
            return false; // Base case: reached the end of a branch

        bool left = findLowestCommonAncestor(root->left, nodeP, nodeQ); // Search LCA in the left subtree
        bool right = findLowestCommonAncestor(root->right, nodeP, nodeQ); // Search LCA in the right subtree
      
        // If both left and right are true, root is the LCA
        if (left && right)
            ancestor = root;
    

        // If either left or right is true and root is either nodeP or nodeQ, current is the LCA
        if ((left || right) && (root->val == nodeP->val || root->val == nodeQ->val)) 
            ancestor = root;
        

        // Return true if root is nodeP or nodeQ or if left or right are true
        return left || right || root->val == nodeP->val || root->val == nodeQ->val;
    }
};