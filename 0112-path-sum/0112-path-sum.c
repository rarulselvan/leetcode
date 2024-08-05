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
    //recursive program
    //pre-order traversal
    if(root==NULL)
        return false;
    int currentSum=targetSum-root->val;

    if(currentSum ==0 && root->left==NULL && root->right==NULL)
        return true;
    
    int result=0;

    if(root->left)
    {
        result=hasPathSum(root->left, currentSum);
        if(result==true)
            return result;
    }
    if(root->right)
        result= result || hasPathSum(root->right, currentSum);

    return result;

}