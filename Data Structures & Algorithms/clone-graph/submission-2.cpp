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
            for (Node* neighbor: curr -> neighbors){
                // This node hasn't been process before
                if (cloned.find(neighbor) == cloned.end()){
                    // mark the node in the cloned
                    cloned[neighbor] = new Node(neighbor -> val);
                    // store the original node in queue
                    q.push(neighbor);
                }
                cloned[curr] -> neighbors.push_back(cloned[neighbor]);
            }
        }

        return cloned[node];

    }
};
