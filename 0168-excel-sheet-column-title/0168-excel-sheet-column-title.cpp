class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char>v(27,'.');
        string ans="";
        for(int i=0; i<26; i++){
            v[i+1] = 'A'+i;
        }
        while(columnNumber>0){
            int n = columnNumber%26;
            if(n==0){
                n=26;
                columnNumber = columnNumber/26 -1;
            }else{
                columnNumber = columnNumber/26;
            } 
            ans.push_back(v[n]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};