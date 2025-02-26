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
    bool isSymmetric(TreeNode* root) 
    {
        return isSymmetricHelper(root, root);
    }
    bool isSymmetricHelper(TreeNode* rootX, TreeNode* rootY)
    {
        if(rootX== NULL && rootY==NULL)
            return true;
        if(rootX== NULL && rootY !=NULL)
            return false;
        if(rootX != NULL && rootY ==NULL)
            return false;

        return ((rootX->val==rootY->val) && isSymmetricHelper(rootX->left, rootY->right) && isSymmetricHelper(rootX->right, rootY->left));
    }
};