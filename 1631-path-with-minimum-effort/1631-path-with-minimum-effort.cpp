class Solution {
    void fun(int &ans, vector<vector<int>> &h, vector<vector<int>> &v, int n, int m, vector<int>&row, vector<int> &col, int i, int j, int curr){
        if(i == 0 && j == 0) {
            ans = min(ans, curr);
            return;
        }
        
        for(int k = 0; k < 4; k++) {
            int r = i + row[k];
            int c = j + col[k];
            
            if(r >= 0 && r < n && c >= 0 && c < m && !v[r][c]) {
                v[r][c] = 1;
                fun(ans, h, v, n, m, row, col, r, c, max(curr, abs(h[i][j] - h[r][c])));
                v[r][c] = 0;
            }
        }
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        /*
        // Got TLE
        int ans = INT_MAX;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        visited[n-1][m-1] = 1;
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};
        fun(ans, heights, visited, n, m, row, col, n-1, m-1, 0);
        return ans;
        */
        
        int n = heights.size();
        int m = heights[0].size();

        // Direction vectors
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};

        // Initialize dp table with maximum values
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = 0;

        bool updated = true;
        while (updated) {
            updated = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < 4; k++) {
                        int r = i + row[k];
                        int c = j + col[k];
                        if (r >= 0 && r < n && c >= 0 && c < m) {
                            int effort = max(dp[i][j], abs(heights[i][j] - heights[r][c]));
                            if (effort < dp[r][c]) {
                                dp[r][c] = effort;
                                updated = true;
                            }
                        }
                    }
                }
            }
        }

        return dp[n-1][m-1];
        
    }
};
