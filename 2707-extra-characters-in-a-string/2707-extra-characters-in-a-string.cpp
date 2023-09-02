class Solution {
    int fun(int i, string &s, unordered_set<string> &st, vector<int> &dp, int n){
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = 1 + fun(i+1, s, st, dp, n);
        for(int j=i; j<n; j++){
            if(st.count(s.substr(i,j-i+1))){
                int pick = fun(j+1, s, st, dp, n);
                dp[i] = min(pick,dp[i]);
            }
        }
        return dp[i];
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n, -1);
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        return fun(0, s, st, dp, n);
    }
};