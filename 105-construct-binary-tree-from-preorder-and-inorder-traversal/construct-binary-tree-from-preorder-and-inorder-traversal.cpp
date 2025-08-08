
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
        unordered_map<int, int> inorderIndexMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex = 0;
        // Build a map from value -> index in inorder
    
        for (int i = 0; i < inorder.size(); i++) 
            inorderIndexMap[inorder[i]] = i;
        
        return buildTreeHelper(preorder, inorder, preIndex, 0, inorder.size() - 1);       
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& preIndex, int left, int right)
    {
        if (left > right)
            return NULL;

        int value = preorder[preIndex++];
        TreeNode* root = new TreeNode(value);

        int index = getIndex(value);//from hash map
        root->left = buildTreeHelper(preorder, inorder, preIndex, left, index - 1);
        root->right = buildTreeHelper(preorder, inorder, preIndex, index + 1, right);

        return root;
    }

    int getIndex(int value)
    {
        return inorderIndexMap[value];
    }
};