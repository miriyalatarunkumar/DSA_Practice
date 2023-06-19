//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        /*
        vector<int> ans;
        unordered_set<int> s;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int n = q.front();
            if(!s.count(n)){
                ans.push_back(n);
                s.insert(n);
                for(auto it : adj[n]){
                    if(!s.count(it)) q.push(it);
                }
            }
            q.pop();
        }
        return ans;
        */
        /*
        // same but different writing style
        // inserting in queue and set simultaneously if not already present in set.
        // inserting in ans while poping out from queue. i.e., first insert and then pop out after traversing it's adjacent nodes
        vector<int> ans;
        unordered_set<int> s;
        queue<int> q;
        q.push(0);
        s.insert(0);
        while(!q.empty()){
            int n = q.front();
            ans.push_back(n);
            for(auto it : adj[n]){
                if(!s.count(it)){
                    q.push(it);
                    s.insert(it); // By doing this, size of queue is reduced
                    // in previous case, all repeated nodes also inserted and checked later.
                }
            }
            q.pop();
        }
        return ans;
        */
        // inserting in queue and making it 1 in hash table if it is 0 initially.
        vector<int> vis(V,0); 
        queue<int> q;
        // push the initial starting node 
        q.push(0);
        vis[0] = 1; 
        vector<int> ans; 
        // iterate till the queue is empty 
        while(!q.empty()) {
           // get the topmost element in the queue 
            int node = q.front(); 
            ans.push_back(node); 
            q.pop(); 
            // traverse for all its neighbours 
            for(auto it : adj[node]) {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    q.push(it); 
                    vis[it] = 1; 
                }
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends