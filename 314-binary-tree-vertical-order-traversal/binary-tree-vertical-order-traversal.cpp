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
    // hd -> level -> multiset of values (to keep order)
    map<int, map<int, vector<int>>> nodes;

public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        DFS(root, 0, 0); // start at hd=0, level=0

        vector<vector<int>> result;

        for (auto& [hd, levelMap] : nodes) 
        {
            vector<int> col;
            for (auto& [level, values] : levelMap)
                col.insert(col.end(), values.begin(), values.end());
            
            result.push_back(col);
        }
        return result;
    }

    void DFS(TreeNode* node, int hd, int level) 
    {
        if (!node) 
            return;

        //nodes[hd][level].insert(node->val);
        nodes[hd][level].push_back(node->val);

        DFS(node->left, hd - 1, level + 1);  // left child: hd - 1
        DFS(node->right, hd + 1, level + 1); // right child: hd + 1
    }
};
