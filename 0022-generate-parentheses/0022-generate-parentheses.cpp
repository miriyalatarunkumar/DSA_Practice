class Solution {
private:
    void fun(int n, vector<string> &ans, string s, int open, int close){
        if(s.size() == n * 2){
            ans.push_back(s);
            return;
        }
        if(open < n) 
            fun(n, ans, s + '(', open + 1, close);
        if(close < open)
            fun(n, ans, s + ')', open, close + 1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        fun(n, ans, s, 0, 0);
        return ans;
    }
};
