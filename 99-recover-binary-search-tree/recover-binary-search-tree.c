/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void recoverTreeBST(struct TreeNode *node,
                struct TreeNode **first,
                struct TreeNode **second,
                struct TreeNode **third,
                struct TreeNode **p) 
{
    if (node )
    {    
        recoverTreeBST(node->left, first, second, third, p);
        
        if (*p && (*p)->val > node->val)
        {  
            if (!*first)
            {
                *first = *p;                   
                *second = node;                 
            } 
            else
            {
                *third = node;                 
                return;                     
            }
        }
        *p = node;
        
        recoverTreeBST(node->right, first, second, third, p);
    }
}
void recoverTree(struct TreeNode* root) 
{
    struct TreeNode *first = NULL;
    struct TreeNode *second = NULL;
    struct TreeNode *third = NULL;\
    struct TreeNode *p=NULL;
    int temp=0;
    
    first = second = third = p = NULL;
    
    recoverTreeBST(root, &first, &second, &third, &p);
    
    if (first)
    {
        if (!third) third = second;
        temp = first->val;            // swap first and third node
        first->val = third->val;
        third->val = temp;
    }
}
