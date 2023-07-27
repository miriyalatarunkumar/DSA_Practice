class Solution {
private:
    void fun(vector<int>& c, int &t, vector<int> &v,  vector<vector<int>> &ans, int i, int sum){
        if(i==c.size())return;
        if(sum == t){
            ans.push_back(v);
            return;
        }
        if(sum>t)return;
        v.push_back(c[i]);
        fun(c, t, v, ans, i, sum+c[i]);
        v.pop_back();
        fun(c, t, v, ans, i+1, sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        fun(candidates, target, v, ans, 0, 0);
        return ans;
    }
};