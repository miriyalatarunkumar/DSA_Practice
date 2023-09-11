class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> m;
        vector<vector<int>> ans;
        for(int i=0; i<groupSizes.size(); i++){
            int element = groupSizes[i];
            int siz = m[element].size();
            if(siz == element){
                ans.push_back(m[element]);
                m[element]={};
            }
            m[element].push_back(i);
        }
        for(auto it : m) ans.push_back(it.second);
        return ans;
    }
};