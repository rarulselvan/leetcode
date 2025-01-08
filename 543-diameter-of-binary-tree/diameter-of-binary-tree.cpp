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
    int ans=0;
    int depth(TreeNode* node)
    {
        if(node == NULL) return 0;
        int L = depth(node->left);
        int R = depth(node->right);
        ans = max(ans, L+R);
        return max(L, R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        depth(root);
        return ans;
    }
};