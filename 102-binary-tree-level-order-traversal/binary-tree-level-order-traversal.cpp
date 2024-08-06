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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
    vector<vector<int>>ans;
    if(root==NULL){return ans;}
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>v;
        int l=q.size();
        for(int i=0; i<l; i++){
            TreeNode* st=q.front();
            q.pop();
            if(st->left!=NULL){q.push(st->left);}
            if(st->right!=NULL){q.push(st->right);}
            v.push_back(st->val);
        }
        ans.push_back(v);
    }
    return ans;
    }
};