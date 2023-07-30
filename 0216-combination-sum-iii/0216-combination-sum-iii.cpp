class Solution {
private:
    void fun(int k, int n, vector<vector<int>> &ans, vector<int> &v, int index, int start, int sum){
        if(index == k){
            if(sum==n) ans.push_back(v);
            return;
        }
        for(int i=start; i<10; i++){
            v.push_back(i);
            fun(k, n, ans, v, index+1, i+1, sum+i);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        fun(k, n, ans, v, 0, 1, 0);
        return ans;
    }
};