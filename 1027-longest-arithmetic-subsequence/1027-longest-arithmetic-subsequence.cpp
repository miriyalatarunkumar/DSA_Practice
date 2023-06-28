class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        /*
        unordered_map<int, unordered_map<int, int>> dp;
        int res = 2, n = A.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)  {
                int d = A[j] - A[i];
                dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;
                res = max(res, dp[d][j]);
            }
        return res;
        */
        int res = 2, n = A.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)  {
                int d = A[j] - A[i] + 1000;
                dp[j][d] = max(2, dp[i][d] + 1);
                res = max(res, dp[j][d]);
            }
        return res;
    }
};