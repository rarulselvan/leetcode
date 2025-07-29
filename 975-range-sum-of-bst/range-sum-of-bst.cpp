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
private:
    int res=0;
public:
    void check(TreeNode* root, int Left, int Right) 
    {
        if(root == NULL) 
            return;

        if(root->val >=Left && root->val <= Right) 
            res+=root->val;
        
        check(root->left, Left, Right);
        check(root->right, Left, Right);
    }

    int rangeSumBST(TreeNode* root, int L, int R)
    {       
        check(root, L, R);
        return res;
    }
};