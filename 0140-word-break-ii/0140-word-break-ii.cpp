class Solution {
private:
    bool isthere(string &st, vector<string> &d){
    return count(d.begin(), d.end(), st)>0;
}
void fun(string &s, vector<string> &d, vector<string> &ans, string &str, int index){
    if(index==s.length()){
        str.pop_back();
        ans.push_back(str);
        return;
    }
    int size = str.length();
    for(int i = index; i<s.length(); i++){
        string st = s.substr(index, i-index+1);
        if(isthere(st, d)){
            str += (st+" ");
            fun(s, d, ans, str, i+1);
            str.pop_back();
            str.erase(size, i-index+1);
        }
    }
}
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string str = "";
        fun(s, wordDict, ans, str, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};