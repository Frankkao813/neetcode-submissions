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
    Node* cloneGraphHelper(Node* node){
        if (node ==nullptr) return nullptr;
        // check whether the node has already been cloned
        if (umap.find(node) != umap.end()){
            return umap[node];
        }
        // create a new node and then add into the list
        Node* newNode = new Node(node -> val);
        umap[node] = newNode;

        // for each neighbor, we also create a new node for them.
        for (Node* neighbor: node -> neighbors){
            Node* neighbor_node = cloneGraphHelper(neighbor);
            newNode -> neighbors.push_back(neighbor_node);
        }

        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        cloneGraphHelper(node);
        return umap[node];
    }
};
