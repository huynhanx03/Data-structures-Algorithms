/*
 Problem: 133. Clone Graph
 Language: cpp
 Runtime: 7 ms (22.77%)
 Memory: 12 MB (77.39%)
 Tags: Hash Table, Depth-First Search, Breadth-First Search, Graph Theory
*/
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
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        unordered_map<Node*, Node*> nodes;

        return clone(node, nodes);
    }

private:
    Node* clone(Node* node, unordered_map<Node*, Node*>& nodes) {
        if (nodes.find(node) != nodes.end()) {
            return nodes[node];
        }

        Node* copy = new Node(node->val);
        nodes[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(clone(neighbor, nodes));
        }

        return copy;
    }
};
