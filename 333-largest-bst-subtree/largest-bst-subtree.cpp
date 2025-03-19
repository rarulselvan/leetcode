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
    int largestSize; // Using "largestSize" to store largest BST subtree size.

    // Public member function to initiate the computation of largest BST subtree size.
    int largestBSTSubtree(TreeNode* root) {
        largestSize = 0;
        dfsHelper(root);
        return largestSize;
    }

    // Helper function to perform depth-first search and return essential info of each subtree.
    vector<int> dfsHelper(TreeNode* root) {
        // Base case: If current node is null, return maximum, minimum and size as specified.
        if (!root) return {INT_MAX, INT_MIN, 0};

        // Recursive cases for left and right subtrees.
        auto leftInfo = dfsHelper(root->left);
        auto rightInfo = dfsHelper(root->right);

        // If current subtree is BST, calculate subtree size and update "largestSize".
        if (leftInfo[1] < root->val && root->val < rightInfo[0]) {
            int subtreeSize = leftInfo[2] + rightInfo[2] + 1;
            largestSize = max(largestSize, subtreeSize);
            // Return a vector containing the minimum value, maximum value, and size of this BST.
            return {min(root->val, leftInfo[0]), max(root->val, rightInfo[1]), subtreeSize};
        }

        // If current subtree is not BST, return values that invalidate the parent node's BST status.
        return {INT_MIN, INT_MAX, 0};
    }
};