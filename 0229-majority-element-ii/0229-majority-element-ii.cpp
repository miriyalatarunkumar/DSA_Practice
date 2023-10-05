class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int el1=INT_MIN, el2=INT_MIN, cnt1=0,cnt2=0;
        for(auto it: nums){
            if(cnt1==0 && it != el2)el1=it;
            else if(cnt2==0 && it != el1)el2=it;
            if(it==el1)cnt1++;
            else if(it==el2)cnt2++;
            else{ cnt1--; cnt2--;}
        }
        cnt1=0; cnt2=0;
        int cnt = nums.size()/3 + 1;
        for(auto it: nums){
            if(it==el1)cnt1++;
            if(it==el2)cnt2++;
        }
        if(cnt1>=cnt)ans.push_back(el1);
        if(cnt2>=cnt)ans.push_back(el2);
        return ans;
    }
};