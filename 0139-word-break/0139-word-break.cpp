class Solution {
private:
    /*
    bool isthere(string &st, vector<string> &d){
        return count(d.begin(), d.end(), st)>0;
    }
    bool fun(string &s, vector<string> &d, int index){
        if(index==s.length()){
            return true;
        }
        for(int i = index; i<s.length(); i++){
            string st = s.substr(index, i-index+1);
            if(isthere(st, d)){
                if(fun(s, d, i+1)) return true;
            }
        }
        return false;
    }
    */
    
    int getMaxLength(const vector<string>& wordDict) {
        return max_element(begin(wordDict), end(wordDict),
                           [](const auto& a, const auto& b) {
                             return a.length() < b.length();
                           })
            ->length();
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        /*
        // got TLE and DP is needed for this problem
        vector<vector<bool>> dp(s, s, 0);
        return fun(s, wordDict, 0, dp);
        */
        
        const int n = s.length();
        const int maxLength = getMaxLength(wordDict);
        const unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
        vector<int> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; ++i)
          for (int j = i - 1; j >= 0; --j) {
            if (i - j > maxLength)
              break;
            if (dp[j] && wordSet.count(s.substr(j, i - j))) {
              dp[i] = true;
              break;
            }
          }

        return dp[n];
    }
};