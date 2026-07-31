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

class Solution {
    unordered_map<Node*, Node*> umap;
    Node* cloneHelper(Node* node){
        if (node == nullptr) return nullptr;
        if (umap.count(node)) return umap[node];

        // copy the current node before exploring the neighbor
        Node* copy = new Node(node -> val);
        umap[node] = copy;

        for (Node* neighbor: node -> neighbors){
            // cloneHelper(neighbor) will return the cloned node pointer
            copy -> neighbors.push_back(cloneHelper(neighbor));
        }
        
        return copy;
    }
public:
    Node* cloneGraph(Node* node) {
        return cloneHelper(node);
    }
};
