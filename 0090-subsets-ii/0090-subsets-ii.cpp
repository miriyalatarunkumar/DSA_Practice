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
    void fun_opti(int i,vector<int> nums,vector<vector<int>>& ans,vector<int>& v){
        if(i<nums.size()){
            v.push_back(nums[i]);
            fun_opti(i+1,nums,ans,v);
            v.pop_back();
            while( i+1 < nums.size() && nums[i] == nums[i+1]) i++;
            fun_opti(i+1,nums,ans,v);
        }
        else ans.push_back(v);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        //fun(0,nums,ans,v);
        fun_opti(0,nums,ans,v);
        sort(ans.begin(),ans.end()); // not asked for it, but can be done
        return ans;
    }
};