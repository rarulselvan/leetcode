/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void goodNodeCount(struct TreeNode* root, int mx, int *res)
{
    if (root == NULL) 
        return;

    if(mx <= root->val)
    {
        *res=*res+1;
        mx = root->val;
    }
    goodNodeCount(root->left, mx, res);
    goodNodeCount(root->right, mx, res);
}

int goodNodes(struct TreeNode* root) 
{
    int ans=0;
    goodNodeCount(root, -100000, &ans);
    return ans;
}
