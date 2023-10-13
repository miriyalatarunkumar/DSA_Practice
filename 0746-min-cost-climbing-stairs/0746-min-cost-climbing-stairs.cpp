class Solution {
    int fun(vector<int>& cost, int i, vector<int> &dp){
        if(i==1)return 0;
        if(i==2)return min(cost[0],cost[1]);
        if(dp[i]!=-1)return dp[i];
        int p = cost[i-1]+fun(cost, i-1, dp);
        int q = cost[i-2]+fun(cost, i-2, dp);
        return dp[i] = min(p,q);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return fun(cost, n, dp);
    }
};