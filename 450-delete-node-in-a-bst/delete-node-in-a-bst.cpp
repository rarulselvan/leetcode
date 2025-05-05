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
    struct TreeNode* subtreeminkey(struct TreeNode *current)
    {
        struct TreeNode* temp=current;
        while(temp->left)
            temp=temp->left;
        return temp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
            return NULL;

        if(key<root->val)
            root->left=deleteNode(root->left, key);
        else if(key >root->val)
            root->right=deleteNode(root->right, key);
        else
        {
            if(root->left==NULL)
            {
                struct TreeNode* temp=root->right;
                delete(root);

                return temp;
            }
            else if(root->right==NULL)
            {
                printf("root->right==NULL");
                struct TreeNode* temp=root->left;
                delete(root);
                return temp;
            }
            else
            {
                struct TreeNode* temp =subtreeminkey(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};