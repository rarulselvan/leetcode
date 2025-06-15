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
    vector <int> ans;
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) 
    {
        ans.push_back(root->val);
        leftViewTree(root->left);
        if(!isLeaf(root))
            LeafView(root);
        rightViewTree(root->right);
        return ans;

    }
    bool isLeaf(TreeNode *node)
    {
        if(node->left == NULL && node->right == NULL)
            return true;
        else
            return false;
    }
    void leftViewTree(TreeNode* root) 
    {
        // exclude leaf node
        if (root == NULL || isLeaf(root))//drop off the leaf nodes
            return;

        ans.push_back(root->val);
        if(root->left)
            leftViewTree(root->left);
        else
            leftViewTree(root->right);
    }
    void LeafView(TreeNode* root) 
    {
         // exclude leaf node
        if (root == NULL)
            return;
        
 

        LeafView(root->left);
               if(isLeaf(root))//drop off the leaf nodes
            ans.push_back(root->val);
        LeafView(root->right);
    }
    void rightViewTree(TreeNode* root) 
    {
        // exclude leaf node
        if (root == NULL || isLeaf(root))//drop off the leaf nodes
            return;

        if(root->right)
            rightViewTree(root->right);
        else
            rightViewTree(root->left);
        ans.push_back(root->val);
    }
};