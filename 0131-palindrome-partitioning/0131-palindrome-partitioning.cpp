class Solution {
private:
    /*
    bool ip(string s){
        int l = 0;
        int r = s.length()-1;
        while(l<=r){
            if(s[l++]!=s[r--])return false;
        }
        return true;
    }
    void fun(string &s, vector<string> &a, vector<vector<string>> &ans, int index){
        if(index==s.length()){
            ans.push_back(a);
            return;
        }
        for(int i = index; i<s.length(); i++){
            string str = s.substr(index, i-index+1);
            if(ip(str)){
                a.push_back(str);
                fun(s, a, ans, i+1);
                a.pop_back();
            }
        }
        
    }
    */
    
    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        /*
        vector<vector<string>> ans;
        vector<string> a;
        fun(s, a, ans, 0);
        return ans;
        */
        
        // DP approach
        
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }
};