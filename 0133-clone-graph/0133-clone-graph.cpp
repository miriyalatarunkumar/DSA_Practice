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
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    clone->neighbors.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    clone->neighbors.push_back(dfs(it,mp));
            }
            return clone;
    }
    
    // unordered_map<int,Node*>m;
    Node* cloneGraph(Node* node) {
        /*
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
        */
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};