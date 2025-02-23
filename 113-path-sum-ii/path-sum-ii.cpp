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
    vector<vector<int>>result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)  
    {        
        //recursive program
        //pre-order traversal
        vector<int> path;
        pathSumDFS(root, targetSum, path);
        return result;
    
    }
    void pathSumDFS(TreeNode* root, int targetSum,  vector<int> path)  
    {
        if(root==NULL)
            return ;

        int currentSum=targetSum-root->val;

        path.push_back(root->val);

        //Means reached the leaf node
        if(currentSum ==0 && root->left==NULL && root->right==NULL)
            result.push_back(path);
        

        pathSumDFS(root->left, currentSum, path);

        //if(root->right)
        pathSumDFS(root->right, currentSum, path);

        path.pop_back();
        return;
    }
};