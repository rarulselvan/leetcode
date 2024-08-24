/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int max(int a, int b)
 {
    return a>b? a:b;
 }
 int height(struct TreeNode* root)
 {
    if(root==NULL)
        return 0;
    return 1+max(height(root->left), height(root->right));
 }
bool isBalanced(struct TreeNode* root)
{
    /// base case: If tree is empty then return true
    if (root == NULL)
        return 1;

    //Get the height of left and right sub trees 
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    printf("%d..%d...%d\n",leftHeight, rightHeight, abs(leftHeight - rightHeight));
    if (abs(leftHeight - rightHeight) <= 1
        && isBalanced(root->left)
        && isBalanced(root->right)
        )
        return 1;
    else
        return 0;
}