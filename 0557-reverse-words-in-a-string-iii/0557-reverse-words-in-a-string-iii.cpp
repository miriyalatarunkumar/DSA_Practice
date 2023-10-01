class Solution {
public:
    string reverseWords(string s) {
        string ans, temp;
        for(auto c: s){
            if(c==' '){
                ans = ans + temp + ' ';
                temp="";
            }
            else temp = c + temp;
        }
        ans = ans + temp;
        return ans;
    }
};