/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
private:
    vector<int> ans;
public:
    vector<int> preorder(Node* root)
    {
        if(root)
        {
            ans.push_back(root->val);
            for(Node* child : root->children)
                preorder(child);
        }
            return ans;
    }
};