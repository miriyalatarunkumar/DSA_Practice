class Solution {
private:
    void fun(string &s, vector<string> &ans, int i){
        while(i<s.length() && s[i]>= '0' && s[i]<= '9')i++;
        if(i==s.length()){
            ans.push_back(s);
            return;
        }
        if(s[i]>='a'&&s[i]<='z'){
            s[i] -= 32;
            fun(s, ans, i+1);
            s[i] += 32;
            fun(s, ans, i+1);
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            s[i] += 32;
            fun(s, ans, i+1);
            s[i] -= 32;
            fun(s, ans, i+1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int i =0;
        fun(s, ans, 0);
        return ans;
    }
};