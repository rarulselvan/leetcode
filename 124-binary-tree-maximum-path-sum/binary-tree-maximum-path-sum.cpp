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
class Solution {
public:
    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) 
        {
            if (!root)
                return 0;
            //max(0, dfs(...)) ensures that negative path sums are ignored (i.e., if a subtree has a negative contribution, we treat it as 0).
            int left = max(0, dfs(root->left));//
            int right = max(0, dfs(root->right));
            //The maximum path sum passing through the current node is calculated as follows
            //"left subtree"+ "right subtree" + "root value"
            ans = max(ans, left + right + root->val);
            //However, this function has to return to the caller...
            return root->val + max(left, right);
        };
        dfs(root);
        return ans;
    }
};