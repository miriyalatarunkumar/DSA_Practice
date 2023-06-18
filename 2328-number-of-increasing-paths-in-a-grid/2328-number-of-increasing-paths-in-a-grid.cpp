class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int mod = 1e9+7;
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        // If dp[i][j] is non-zero, it means we have got the value of dfs(i, j),
        // so just return dp[i][j].
        if (dp[i][j] != 0)
            return dp[i][j];

        // Otherwise, set answer = 1, the path made of grid[i][j] itself.
        int answer = 1;

        // Check its four neighbor cells, if a neighbor cell grid[prevI][prevJ] has a
        // smaller value, we move to this cell and solve the subproblem: dfs(prevI, prevJ).
        for (auto d : directions) {
            int prevI = i + d[0], prevJ = j + d[1];
            if (0 <= prevI && prevI < grid.size() && 0 <= prevJ && prevJ < grid[0].size() && grid[prevI][prevJ] < grid[i][j]) 
            {
                answer += dfs(grid, prevI, prevJ,dp);
                answer %= mod;
            }
        }

        // Update dp[i][j], so that we don't recalculate its value later.
        dp[i][j] = answer;
        return answer;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n) );
        
        // Iterate over all cells grid[i][j] and sum over dfs(i, j).
        int answer = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                answer = (answer + dfs(grid, i, j, dp)) % mod;
            }
        }

        return answer;
    }
};