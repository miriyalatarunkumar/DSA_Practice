//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
private:
    bool issafe(bool graph[101][101], int n, int node, vector<int> &colour, int col){
        for(int i=0; i<n; i++){
            if(graph[node][i] && colour[i]==col) return false;
        }
        return true;
    }
    bool fun(bool graph[101][101], int m, int n, int node, vector<int> &colour){
        if(node==n)return true;
        for(int col =1; col<=m; col++){
            if(issafe(graph, n, node, colour, col)){
                colour[node]=col;
                if (fun(graph, m, n, node+1, colour)) return true;
                else colour[node]=0;
            }
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> colour(n, 0);
        return fun(graph, m, n, 0, colour);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends