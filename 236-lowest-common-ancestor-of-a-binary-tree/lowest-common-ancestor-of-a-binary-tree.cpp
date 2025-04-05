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
        //Base case 
        if (root==NULL || root == p || root == q) return root;

        //Find the p & q on left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root; // If p and q are found in different subtrees
        else
        {
         //   return left ? left : right; // Otherwise, return the non-null subtree
            if(left)
                return left;
            else if(right)
                return right;
            else
                return NULL;
        }
    }
};