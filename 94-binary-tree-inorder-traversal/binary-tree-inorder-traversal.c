/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getCount(struct TreeNode* root)
{
    if(root)
        return 1+getCount(root->left)+getCount(root->right);
    else
        return 0;
}
void inorder(struct TreeNode* root, int *arr, int *size)
{
    if(root)
    {
        inorder(root->left, arr, size);
        arr[*size]=root->val;
        *size=*size+1;
        inorder(root->right, arr, size);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int count=getCount(root);
    int *arr=(int *) malloc(sizeof(int)*count);
    *returnSize=0;
    inorder(root, arr, returnSize);        
    return arr;
}