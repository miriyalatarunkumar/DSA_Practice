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
    unordered_map<int,Node*>m;
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        Node* root = NULL;
        if(!m.count(node->val)){
            root = new Node(node->val);
            m[node->val]=root;
        }
        else return m[node->val];
        if(!node->neighbors.empty()){
            for(auto it : node->neighbors){
                root->neighbors.push_back(cloneGraph(it));
            }
        }
        return root;
    }
};