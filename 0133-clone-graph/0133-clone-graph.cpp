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
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If the node has already been cloned, return the cloned instance
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Clone the current node (without neighbors initially)
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Recursively clone and link all neighbor nodes
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};