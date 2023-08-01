class Solution {
private:
    void fun(int n, int k, vector<vector<int>> &ans, vector<int> &v, int index, int val){
        if(index==k){
            ans.push_back(v);
            return;
        }
        for(int i = val; i<=n; i++){
            v.push_back(i);
            fun(n, k, ans, v, index+1, i+1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        fun(n, k, ans, v, 0, 1);
        return ans;
    }
};