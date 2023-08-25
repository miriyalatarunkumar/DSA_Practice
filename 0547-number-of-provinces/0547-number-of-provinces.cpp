class Solution {
private:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited, int n){
    visited[i]=1;
    for(int j=0; j<n; j++){
        if(isConnected[i][j] && !visited[j]){
            dfs(j,isConnected, visited, n);
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        /*
        int ans =0, n=isConnected.size();
        vector<bool> visited(n,0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(i, isConnected, visited, n);
            }
        }
        return ans;
        */
        
        int ans =0, n=isConnected.size();
        vector<bool> visited(n,0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int k=q.front();
                    visited[k]=1;
                    q.pop();
                    for(int j=0; j<n; j++){
                        if(isConnected[k][j] && !visited[j]) q.push(j);
                    }
                }
            }
        }
        return ans;
    }
};