class Solution {
private:
    int fun(int n, int i, vector<int> &dp){
        if(i==0)return 1;
        if(i<0)return 0;
        if(dp[i]!= -1) return dp[i];
        int first = fun(n, i-1, dp);
        int second = fun(n, i-2, dp);
        return dp[i] = first+second;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return fun(n, n, dp);
    }
};