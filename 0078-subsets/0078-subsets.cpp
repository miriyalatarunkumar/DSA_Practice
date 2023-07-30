class Solution {
private:
    void fun(vector<int> &nums, vector<vector<int>> & ans, vector<int> v, int i){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        fun(nums, ans, v, i+1);
        v.pop_back();
        fun(nums, ans, v, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        fun(nums, ans, v, 0);
        return ans;
    }
};