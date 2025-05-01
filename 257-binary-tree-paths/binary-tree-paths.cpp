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
    vector<string>ans;
   
public:

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string subAns;
        binaryTreePathsHelper(root, subAns);
        return ans;
    }
    void binaryTreePathsHelper(TreeNode* root, string subAns) 
    {
        if (!root) return;

        // Append current node value
        if (!subAns.empty()) subAns += "->";
        subAns += to_string(root->val);

        // If it's a leaf, add path to result
        if (!root->left && !root->right) {
            ans.push_back(subAns);
            return;
        }

        binaryTreePathsHelper(root->left, subAns);
        binaryTreePathsHelper(root->right, subAns);
    }
};