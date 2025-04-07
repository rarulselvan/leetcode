/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) 
    {
        if (!node)
            return NULL;
        //if (visited.count(node)) 
        if (visited[node]) 
        {   
            //Avoid the cylcic loop...else will go indefinetely
            return visited[node]; // this will be added as a neighbor..no need to create a new one
        }

        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (auto& e : node->neighbors)
            clone->neighbors.push_back(cloneGraph(e));//fully constructed nodes are added here.
        
        return clone;
    }
};