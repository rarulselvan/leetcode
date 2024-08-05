/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) 
{
    // Preorder traversal
    //subtract the visited node from the sum

    // handle the base case for the recursion to terminate
    if(root==NULL)
        return false;

    int result=0;
    
    int currentSum=targetSum-root->val;
    if(currentSum ==0 && root->left==0 && root->right==0)
        return true;

    int ans=0;
    if(root->left)
        ans=hasPathSum(root->left, currentSum);
    if(root->right)
        ans=ans || hasPathSum(root->right, currentSum);
    return ans;   
}