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
    void check(TreeNode* root, int Left, int Right, int &res) 
    {
        if(root == NULL) 
            return;

        if(root->val >= Left && root->val <= Right) 
            res+=root->val;
        
        check(root->left, Left, Right, res);
        check(root->right, Left, Right, res);
    }

    int rangeSumBST(TreeNode* root, int L, int R)
    {
        if(root == NULL)
            return 0;
    
        int res = 0;
        check(root, L, R, res);
        return res;
    }
};