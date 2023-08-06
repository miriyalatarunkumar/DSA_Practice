class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int s1 = nums[n-1], s2 = nums[n-2];
        for(int i = n-3; i>=0; i--){
            if((nums[i]+s2)>s1){
                ans = nums[i]+s1+s2;
                break;
            }
            else{
                s1=s2;
                s2=nums[i];
            }
        }
        return ans;
    }
};