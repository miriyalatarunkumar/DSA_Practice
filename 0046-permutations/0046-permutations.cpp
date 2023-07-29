class Solution {
private:
    void fun(vector<int> &nums, int index, vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            fun(nums, index+1, ans);
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        fun(nums, 0, ans);
        return ans;
    }
};