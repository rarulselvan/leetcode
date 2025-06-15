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
private:
    TreeNode* prev = nullptr; // Pointer to keep track of the previous node during in-order traversal
    TreeNode* first = nullptr;    // Pointer to the first node that is out of the expected order
    TreeNode* second = nullptr;   // Pointer to the second node that is out of the expected order

public:
    void recoverTree(TreeNode* Originalroot) 
    {
        function<void(TreeNode*)> findTwoNodes;
        findTwoNodes=[&](TreeNode* root) 
        {
            if(root)
            {
                findTwoNodes(root->left);
                if(prev !=NULL)
                {
                    if(prev->val > root->val)
                    {
                        //first and second need to be swapped..however if first and second in not adjecent to each other?  iterate the entire tree and update the second
                        if(first==NULL)
                            first=prev;
                        second=root;                        
                    }
                }
                prev=root;
                findTwoNodes(root->right);
            }
        };
        findTwoNodes(Originalroot);
        if(first && second)
            swap(first->val, second->val);
    }
};
