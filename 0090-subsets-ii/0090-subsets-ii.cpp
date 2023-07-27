class Solution {
private:
    void fun(vector<int>& nums, int n, vector<int> &v, vector<vector<int>> &ans, int i){
        if(i==n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        fun(nums, n, v, ans, i+1);
        v.pop_back();
        int num = nums[i];
        while(i < n && nums[i]==num){i++;}
        fun(nums, n, v, ans, i);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        fun(nums, n, v, ans, 0);
        return ans;
    }
};