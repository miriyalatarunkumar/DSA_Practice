class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1)return ans;
        vector<int> prev = {1,1};
        ans.push_back(prev);
        for(int i=3; i<=numRows; i++){
            vector<int> curr;
            int n = prev.size();
            curr.push_back(prev[0]);
            for(int j=1; j<n; j++) curr.push_back(prev[j]+prev[j-1]);
            curr.push_back(prev[n-1]);
            ans.push_back(curr);
            prev=curr;
        }
        return ans;
    }
};