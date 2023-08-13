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
    void dfs(Node* original, Node* clone, unordered_map<Node*, Node*>& cloneMap) {
        cloneMap[original] = clone;
        
        for (Node* nbr : original->neighbors) {
            if (cloneMap.find(nbr) == cloneMap.end()) {
                Node* newNbr = new Node(nbr->val);
                clone->neighbors.push_back(newNbr);
                dfs(nbr, newNbr, cloneMap);
            } else {
                clone->neighbors.push_back(cloneMap[nbr]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if (node==NULL) return NULL;
        unordered_map<Node*, Node*> cloneMap; // Map to store original node to cloned node mapping
        Node* head = new Node(node->val); // Create a new node as the starting point
        
        dfs(node, head, cloneMap); // Clone the graph using DFS
        
        return head;
    }
};
