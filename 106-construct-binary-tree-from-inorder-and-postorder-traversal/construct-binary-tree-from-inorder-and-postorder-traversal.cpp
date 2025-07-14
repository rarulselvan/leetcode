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
        TreeNode *buildUtil(vector<int> &inorder, vector<int> &postorder, 
                    int inStrt, int inEnd, int &pIndex) 
        {

        // if inStart is greater than inEnd return nullptr
        if (inStrt > inEnd)
            return nullptr;

        // Pick current node from Postorder traversal using
        //   postIndex and decrement postIndex
        TreeNode *root = new TreeNode(postorder[pIndex]);
        pIndex--;

        // If this node has no children then return
        if (inStrt == inEnd)
            return root;

        // Else find the index of this node in Inorder traversal
        int iIndex = search(inorder, inStrt, inEnd, root->val);

        // Using index in Inorder traversal, construct left and right subtrees
        // In the example(Description) post order traversal begins from left to right
        //(in post order traversal...after 3... 20 will appear from end) hence construct the rigght subtree and then left subtree
        root->right = buildUtil(inorder, postorder, iIndex + 1, inEnd, pIndex);
        root->left = buildUtil(inorder, postorder, inStrt, iIndex - 1, pIndex);
        
        return root;
    }

    // This function mainly initializes index of root
    // and calls buildUtil()
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        int n = inorder.size();
        int pIndex = n - 1;
        return buildUtil(inorder, postorder, 0, n - 1, pIndex);
    }
    int search(vector<int> &arr, int strt, int end, int value) 
    {
        int i;
        for (i = strt; i <= end; i++) 
        {
            if (arr[i] == value)
                break;
        }
        return i;
    }
};