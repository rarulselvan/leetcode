/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL)
            return " null";
        else
        {
            string rt=to_string(root->val);
            string le=serialize(root->left);
            string rgt=serialize(root->right);
           // cout << rt+le+rgt<< "  "<<endl;
            return " "+rt+le+rgt;
        }

    }
    TreeNode* buildTree(istringstream& ss)
    {
        string s;
        ss >> s;
        
        if (s == "null")
			return NULL;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
            
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return buildTree(ss);
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));