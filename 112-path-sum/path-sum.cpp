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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {        
        //recursive program .... pre-order traversal
        if(root==NULL)
            return false;

        int currentSum=targetSum-root->val;
        
        //base case
        if(currentSum ==0 && root->left==NULL && root->right==NULL)
            return true;
        
        bool result=0;

       
        result=hasPathSum(root->left, currentSum);
        if(result==true)
            return result;
        //If thie path is false attempt the right tree

        result= hasPathSum(root->right, currentSum);

        return result;
    }
};