class Solution {
private:
    int robs(vector<int>& nums) {
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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        int a = robs(temp1);
        int b = robs(temp2);
        return max(a,b);
    }
};