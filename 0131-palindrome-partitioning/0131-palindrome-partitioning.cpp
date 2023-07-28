class Solution {
private:
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
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> a;
        fun(s, a, ans, 0);
        return ans;
    }
};