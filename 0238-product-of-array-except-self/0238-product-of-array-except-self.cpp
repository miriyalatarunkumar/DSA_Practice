class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pro = 1;
        for(int i=0; i<n; i++){
            ans[i]=pro;
            pro *= nums[i];
        }
        pro =1;
        for(int i=n-1; i>=0; i--){
            ans[i] *= pro;
            pro *= nums[i];
        }
        return ans;
    }
};