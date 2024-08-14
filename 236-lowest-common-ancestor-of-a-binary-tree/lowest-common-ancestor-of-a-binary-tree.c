/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /*
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if(root == NULL ||root->val==p->val || root->val==q->val)
        return NULL;
    if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if(p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else 
        return root;
}
*/

struct TreeNode* lowestCommonAncestor(struct TreeNode*  root, struct TreeNode* n1, struct TreeNode* n2)
{
    // Base case
    if (root == NULL)
        return NULL;
 
    if (root->val == n1->val || root->val == n2->val)
        return root;
 
    // Look for keys in left subtree
    struct TreeNode* left_lca = lowestCommonAncestor(root->left, n1, n2);
    // Look for keys in right subtree
    struct TreeNode* right_lca = lowestCommonAncestor(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one key is present in left subtree and other is present in right sub tree, hence this node is the LCA
    if (left_lca && right_lca)
        return root;
 
    // Otherwise check if left subtree or right subtree is
    return (left_lca != NULL) ? left_lca : right_lca;
}