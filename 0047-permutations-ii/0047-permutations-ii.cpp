class Solution {
private:
    void fun(int pos, vector<int>& arr, int n, vector<vector<int>>& ans) {
        if(pos==n-1){
            if(find(ans.begin(),ans.end(),arr)==ans.end()){
                    ans.push_back(arr);   
                }
        }
        else{
            for(int i = pos; i<n; i++){
                swap(arr[i],arr[pos]);
                fun(pos+1,arr,n,ans);
                swap(arr[i],arr[pos]);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        fun(0, arr, n, ans);
        return ans;
    }
};
