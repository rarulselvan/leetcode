/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* subtreeminkey(struct TreeNode *current)
{
	struct TreeNode* temp=current;
	while(temp->left)
		temp=temp->left;
    printf("subtreeminkey=%d", current->val);
	return temp;
}
struct TreeNode* deleteNode(struct TreeNode* root, int key) 
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
            printf("root->left==NULL");
            struct TreeNode* temp=root->right;
            //free(root);

            return temp;
        }
        else if(root->right==NULL)
        {
            printf("root->right==NULL");
            struct TreeNode* temp=root->left;
            //free(root);
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