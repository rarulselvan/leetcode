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
    TreeNode* prev=NULL;
public:
/*
    bool isBST(struct TreeNode* root,struct TreeNode* &prev)
    {
        if(root)
        {
            if(isBST(root->left, prev) ==false)
                return false;
            if(prev)
            {
                if(prev->val >= root->val)
                    return false;
            }
            prev=root;
            
            if(isBST(root->right, prev)==false)
                return false;
        }
        return true;
    }*/

    bool isValidBST(struct TreeNode* root) 
    {
        if(root)
        {
            if(isValidBST(root->left)==false)
                return false;
            if(prev)
            {
                if(prev->val>=root->val)
                    return false;
            }
            prev=root;

            if(isValidBST(root->right)==false)
                return false;
        }
        return true;
    }
};
