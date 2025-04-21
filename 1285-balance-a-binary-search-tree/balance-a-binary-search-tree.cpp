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
    vector<int> nums;
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        dfs(root);
        return buildBalancedBST(0, nums.size() - 1);
    }
    void dfs(TreeNode *root)
    {
        if(root)
        {
            dfs(root->left);
            nums.push_back(root->val);
            dfs(root->right);
        }
    }
    TreeNode * buildBalancedBST(int start, int end)
    {
        TreeNode *root=NULL;
        if(start<=end)
        {
            int mid=start+(end-start)/2;
            root= new TreeNode(nums[mid]);
            root->left=buildBalancedBST(start, mid-1);
            root->right=buildBalancedBST(mid+1, end);
        }
        return root;
    }
};