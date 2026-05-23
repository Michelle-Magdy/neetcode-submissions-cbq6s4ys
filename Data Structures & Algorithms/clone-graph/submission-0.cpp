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
        unordered_map<Node*,Node*> visited;
        Node* n = dfs(node,visited);
        return n;
    }

    Node* dfs(Node* node, unordered_map<Node*,Node*>& visited){
        if(node == nullptr){
            return node;
        }

        if(visited.count(node)){
            return visited[node];
        }
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for(Node* n: node->neighbors){
            Node* neigNode = dfs(n,visited);
            newNode->neighbors.push_back(neigNode);
        }
        return newNode;
    }
};
