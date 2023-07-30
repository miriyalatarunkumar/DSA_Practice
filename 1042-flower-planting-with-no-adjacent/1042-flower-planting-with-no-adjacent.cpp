class Solution {
private:
    bool issafe(vector<vector<int>>& graph, vector<int> &colors, int node, int color){
        for(int i = 0; i < graph[node].size(); i++){
            if(colors[graph[node][i] - 1] == color) // 0-based indexing
                return false;
        }
        return true;
    }

    bool fun(int n, vector<vector<int>>& graph, vector<int> &colors, int node){
        if(node > n) return true;
        for(int color = 1; color <= 4; color++){
            if(issafe(graph, colors, node, color)){
                colors[node - 1] = color; // 0-based indexing
                if(fun(n, graph, colors, node + 1)) return true;
                colors[node - 1] = 0; // 0-based indexing
            }
        }
        return false;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> colors(n, 0); // color of each node, 0-based indexing
        vector<vector<int>> graph(n + 1); // adjacency list of the graph, 1-based indexing
        for(int i = 0; i < paths.size(); i++){
            int u = paths[i][0], v = paths[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        fun(n, graph, colors, 1);
        return colors;
    }
};
