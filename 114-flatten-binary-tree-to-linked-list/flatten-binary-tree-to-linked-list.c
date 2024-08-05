/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) 
{
    //In order traversal
    static struct TreeNode*  prev = NULL;
	if(root !=NULL)
	{
        //preserve the left and right for recursive call because we are setting left and right to NULL (singly list)
        struct TreeNode  *left=root->left;
        struct TreeNode  *right=root->right;
		if(prev==NULL)
		{
        	prev=root;
            prev->left=NULL;//singly list
        }
		else
		{
			prev->right=root;
            prev->left=NULL;//singly list
            prev=root;
		}
		flatten(left);
		flatten(right);
	}
}