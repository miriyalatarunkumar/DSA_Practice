class Solution {
    int fun(int target, vector<int>& nums, vector<int>& dp) {
        if (target < 0) return 0;
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];
        
        int total = 0;
        for (int num : nums) {
            total += fun(target - num, nums, dp);
        }
        
        return dp[target] = total;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return fun(target, nums, dp);
    }
};
