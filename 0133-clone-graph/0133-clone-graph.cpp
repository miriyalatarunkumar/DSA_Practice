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
    unordered_map<Node* , Node*> mp;
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
        /*
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
        */
        if(node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }
        
        // for a node, we will check whether we already creates a copy of thiis or not. If it is present in map that means we already creates a copy of this.
        //But if not present in map, that means we have not a copy of this.
        // Also, if we create a copy, then being a good neighbor, we find whether our neighbor have a copy or not, so we will travel all around our adjcant.
        
        if(mp.find(node) == mp.end()) // if not present in map
        {
            mp[node] = new Node(node -> val, {}); // make a copy
            
            for(auto adj: node -> neighbors) // travel in adjcant
            {
                mp[node] -> neighbors.push_back(cloneGraph(adj)); //add copy
            }
        }
        
        return mp[node]; // and at last, return mp[node] as till now we clone our whole graph
    }
};