class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        stack<int> potentialK;
        int secondMax = INT_MIN;

        for(int i = n-1; i >= 0; i--){
            if(nums[i] < secondMax) return true;
            while(!potentialK.empty() && nums[i] > potentialK.top()){
                secondMax = potentialK.top();
                potentialK.pop();
            }
            potentialK.push(nums[i]);
        }
        return false;
    }
};
