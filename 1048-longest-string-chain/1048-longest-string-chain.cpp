class Solution {
    int dfs(vector<string> &words, string s, int index, vector<int> &dp, unordered_map<string,int> &m){
        int n = s.length(), maxi = 1;
        if(n==0)return 0;
        if(dp[index]!=-1)return dp[index];
        for(int i=0; i<n; i++){
            string left, right, str;
            left = s.substr(0, i);
            if(i<n-1) right = s.substr(i+1);
            str = left+right;
            int val=0;
            if(m.count(str))val = 1+dfs(words, str, m[str], dp, m);
            maxi = max(maxi,val);
        }
        return dp[index]=maxi;
    }
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> m;
        int n = words.size();
        for(int i=0; i<n; i++)m[words[i]]=i;
        vector<int> dp(n, -1);
        for(int i=0; i<n; i++)dfs(words, words[i], i, dp, m);
        auto ans = max_element(dp.begin(), dp.end());
        return *ans;
    }
};