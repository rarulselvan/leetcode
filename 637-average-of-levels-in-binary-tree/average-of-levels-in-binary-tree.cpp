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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        queue <TreeNode *>q;
        q.push(root);
        vector<double>ans;

        while(!q.empty())
        {
            double sum=0;
            int count=q.size();
            for(int i=count; i; i--)
            {
                auto node = q.front();
                q.pop();
                sum=sum+node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            sum=sum/count;
            ans.push_back(sum);
        }
        return ans;
    }
};