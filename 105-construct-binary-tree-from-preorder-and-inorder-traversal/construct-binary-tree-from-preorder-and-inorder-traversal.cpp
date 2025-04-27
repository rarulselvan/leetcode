
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex = 0;
        return buildTreeHelper(preorder, inorder, preIndex, 0, inorder.size() - 1);       
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& preIndex, int left, int right)
    {
        if (left > right)
            return NULL;

        int value = preorder[preIndex++];
        TreeNode* root = new TreeNode(value);

        int index = getIndex(inorder, left, right, value);
        root->left = buildTreeHelper(preorder, inorder, preIndex, left, index - 1);
        root->right = buildTreeHelper(preorder, inorder, preIndex, index + 1, right);

        return root;
    }

    int getIndex(const vector<int>& inorder, int left, int right, int value)
    {
        
        for (int i = 0; i < inorder.size(); ++i)
        {
            if (inorder[i] == value)
                return i;
        }
        /*
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(value<inorder[mid])
                right=mid-1;
            else if(value>inorder[mid])
                left=mid+1;
            else
                return mid;
        }*/
        return -1; // Should not happen if input is valid
    }
};

