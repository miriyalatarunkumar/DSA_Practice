class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findStartingIndex(nums, target);
        int end = findEndingIndex(nums, target);
        return {start, end};
    }
    
private:
    int findStartingIndex(vector<int>& nums, int target) {
        int index = -1;
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] >= target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
            if(nums[m] == target) {
                index = m;
            }
        }
        return index;
    }
    
    int findEndingIndex(vector<int>& nums, int target) {
        int index = -1;
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] <= target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
            if(nums[m] == target) {
                index = m;
            }
        }
        return index;
    }
};
