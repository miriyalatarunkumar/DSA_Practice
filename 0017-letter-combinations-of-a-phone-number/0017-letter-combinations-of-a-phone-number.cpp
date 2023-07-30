class Solution {
private:
    void fun(string &digits, vector<string> &ans, string &s, unordered_map<char, string> &m, int index){
        if(index == digits.length()){
            ans.push_back(s);
            return;
        }
        for(int i=0; i<m[digits[index]].length(); i++){
            s.push_back(m[digits[index]][i]);
            fun(digits, ans, s, m, index+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string s;
        unordered_map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        fun(digits, ans, s, m, 0);
        return ans;
    }
};