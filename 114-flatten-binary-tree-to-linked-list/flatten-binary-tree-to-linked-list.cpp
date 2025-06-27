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
    void flatten( TreeNode* root)
    {
        stack< TreeNode *>st;
        st.push(root);
        // If the left subtree was flattened, merge it with the current node
        // If the right subtree was flattened, return its tail node
        // If neither subtree was flattened, return the current node as the tail node
        while(!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();

            if(curr==NULL) 
                return;
                
            if(curr->right!=NULL) 
                st.push(curr->right);
            if(curr->left!=NULL) 
                st.push(curr->left);

            if(st.empty()!=true)// Set the left child of the current node to null
                curr->right = st.top();

            curr->left = NULL;
        }
        return;
    }
};