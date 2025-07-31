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
    int botLeftValDeep=0;
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        int maxLevel=0;
        findBottomLeftValueHelper(root, 1, &maxLevel);
        return botLeftValDeep;
    }
    void findBottomLeftValueHelper(TreeNode *root, int level, int *maxLevel)
    {
        if(!root) return;
        if(*maxLevel < level)
        {
            botLeftValDeep=root->val;
            *maxLevel=level;
        }
        findBottomLeftValueHelper(root->left, level+1, maxLevel);
        findBottomLeftValueHelper(root->right, level+1, maxLevel);
    }
};