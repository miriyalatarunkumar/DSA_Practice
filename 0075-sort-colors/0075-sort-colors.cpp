class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high=nums.size()-1,low=0,mid=0;
        while(mid<=high){
            if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else mid++;
        }
    }
};