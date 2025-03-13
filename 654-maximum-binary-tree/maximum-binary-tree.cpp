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
   TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
   {
        if (nums.empty()) return nullptr;
        
        auto max_it = max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(*max_it);
        
        vector<int> left_nums(nums.begin(), max_it);
        vector<int> right_nums(max_it + 1, nums.end());
        
        root->left = constructMaximumBinaryTree(left_nums);
        root->right = constructMaximumBinaryTree(right_nums);
        
        return root;
    }
};