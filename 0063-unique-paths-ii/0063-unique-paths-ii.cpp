class Solution {
private:
    int fun(int m, int n, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==0 && j==0 && grid[0][0] != 1) return 1;
        if(i<0 || j <0 || grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = fun(m, n, i-1, j, grid, dp);
        int left = fun(m, n, i, j-1, grid, dp);
        return dp[i][j] = up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        if(grid[0][0] == 1) return 0;
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return fun(m, n, m-1, n-1, grid, dp);
        /*
        vector<int> prev(n, 0), curr(n,0);
        prev[0] = 1;
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }
                int up = prev[j];
                int left = 0;
                if(j>0) left = curr[j-1];
                curr[j] = up+left;
            }
            prev = curr;
        }
        return prev[n-1];
        */
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j-1];
                }
            }
        }

        return dp[n-1];
    }
};