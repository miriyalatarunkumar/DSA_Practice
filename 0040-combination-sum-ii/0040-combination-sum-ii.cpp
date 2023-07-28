class Solution {
private:
    void fun(vector<int> &c, int t, vector<vector<int>> &ans, vector<int> &v, int i, int sum){
        if(sum==t){
            ans.push_back(v);
            return;
        }
        if(i==c.size())return;
        if(sum>t)return;
        v.push_back(c[i]);
        fun(c, t, ans, v, i+1, sum+c[i]);
        v.pop_back();
        while(i+1<c.size() && c[i]==c[i+1])i++;
        fun(c, t, ans, v, i+1, sum);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        fun(candidates, target, ans, v, 0, 0);
        return ans;
    }
};