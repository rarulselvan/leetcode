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
    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;
    
        //function<int (TreeNode*)> dfs=[&](TreeNode* root)
        function<int (TreeNode *)>dfs;
        dfs=[&](TreeNode* root)
        {
            if(root==NULL)
                return 0;
            
            int leftMax= max(0,dfs(root->left)); //max is required for negative weights
            int rightMax= max(0,dfs(root->right)); //max is required for negative weights

            ans=max(ans, root->val+leftMax+rightMax); //global calculation
            return(max(leftMax, rightMax)+root->val); //this function return value...for the previous caller this function computes left and right subtree and picks the macimum out of it
        };
        dfs(root);
        return ans;
    }
};