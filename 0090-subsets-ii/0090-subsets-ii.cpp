class Solution {
    void fun(int i,vector<int> nums,vector<vector<int>>& ans,vector<int>& v){
        if(i<nums.size()){
            v.push_back(nums[i]);
            fun(i+1,nums,ans,v);
            v.pop_back();
            fun(i+1,nums,ans,v);
        }
        else {
            if( find(ans.begin(),ans.end(),v) == ans.end()){
                ans.push_back(v);  
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        fun(0,nums,ans,v);
        return ans;
    }
};