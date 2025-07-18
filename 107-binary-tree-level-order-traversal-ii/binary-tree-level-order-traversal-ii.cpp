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
        vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        queue<TreeNode *>q;
        if(!root)
            return {};
        q.push(root);

       while (!q.empty()) 
       {
            vector<int> currentLevel;
            for (int n = q.size(); n; n--) 
            {
                auto node = q.front();
                q.pop();
               
                currentLevel.push_back(node->val);
                if (node->left) 
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(currentLevel);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};