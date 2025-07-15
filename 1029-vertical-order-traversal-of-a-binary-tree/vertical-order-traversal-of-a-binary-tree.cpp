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
/*class Solution
{
    unordered_map<int, vector<int>> Map;
    int minHD = 0;
    int maxHD = 0;
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // Start DFS from horizontal distance 0
        DFS(root, 0);
        
        vector<vector<int>> res;
        for (int hd = minHD; hd <= maxHD; ++hd) {
            if (Map.find(hd) != Map.end()) {
                res.push_back(Map[hd]);
            }
        }
        return res;
    }

    void DFS(TreeNode* root, int hD) 
    {
        if (root == nullptr) 
            return;
        
        // Store the node at current horizontal distance
        Map[hD].push_back(root->val);

        // Update min/max HD range
        minHD = min(minHD, hD);
        maxHD = max(maxHD, hD);
        
        // Recurse left and right with updated HD
       
        DFS(root->right, hD + 1);
        DFS(root->left, hD - 1);  
    }
}; */

/*class Solution 
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> result;
        if (!root) 
            return {};

        map<int, map<int, multiset<int>>> nodes; // hd -> level -> list of node values
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {hd, level}}
        
        q.push({root, {0, 0}});

        while (!q.empty()) 
        {
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int hd = curr.second.first;
            int level = curr.second.second;

            nodes[hd][level].insert(node->val);

            if (node->left)
                q.push({node->left, {hd - 1, level + 1}});
            if (node->right)
                q.push({node->right, {hd + 1, level + 1}});
        }

        for (auto& [hd, levelMap] : nodes) {
            vector<int> col;
            for (auto& [level, vals] : levelMap) {
                col.insert(col.end(), vals.begin(), vals.end());
            }
            result.push_back(col);
        }

        return result;
    }
};*/

class Solution 
{
    // hd -> level -> multiset of values (to keep order)
    map<int, map<int, multiset<int>>> nodes;

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
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

        nodes[hd][level].insert(node->val);

        DFS(node->left, hd - 1, level + 1);  // left child: hd - 1
        DFS(node->right, hd + 1, level + 1); // right child: hd + 1
    }
};