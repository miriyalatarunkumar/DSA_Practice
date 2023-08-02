class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int lpro = 1;
        int rpro = 1;
        for(int i=0; i<n; i++){
            if(lpro == 0) lpro = 1;
            if(rpro == 0) rpro = 1;
            lpro *= nums[i];
            rpro *= nums[n-i-1];
            ans = max( ans, max( lpro, rpro ) );
        }
        return ans;
    }
};