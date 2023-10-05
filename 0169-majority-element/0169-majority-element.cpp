class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, count=0;
        for(auto it: nums){
            if(count==0)ans = it;
            if(ans==it)count++;
            else count--;
        }
        return ans;
    }
};