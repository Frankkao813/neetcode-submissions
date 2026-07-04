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
    unordered_map<Node*, Node*> cloned;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        // push the first node in the queue and also the cloned dictionary
        queue<Node*> q;
        cloned[node] = new Node(node -> val);
        q.push(node);

        while (!q.empty()){
            Node* curr = q.front();
            q.pop();
            // process the neighbor
            for (Node* neighbor: curr -> neighbors){
                // see if the node has already been added to the cloned list before
                if (cloned.find(neighbor) == cloned.end()){
                    cloned[neighbor] = new Node(neighbor -> val);
                    q.push(neighbor);
                }
                cloned[curr] -> neighbors.push_back(cloned[neighbor]);
            }
        }

        return cloned[node];

    }
};
