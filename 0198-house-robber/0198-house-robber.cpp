class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i=1; i<nums.size(); i++){
            int pick = nums[i]+prev2;
            int npick = prev1;
            int curr = max(pick,npick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};