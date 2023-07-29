class Solution {
private:
    void fun(int n, vector<vector<string>> &ans, vector<string> &v, vector<bool> &c, vector<bool> &rd, vector<bool> &ld, int index){
        if(index==n){
            ans.push_back(v);
            return;
        }
        for(int i=0; i<n; i++){
            if(!c[i] && !rd[i+index] && !ld[i-index+n-1]){
                c[i]=1;
                rd[i+index]=1;
                ld[i-index+n-1]=1;
                v[index][i]='Q';
                fun(n, ans, v, c, rd, ld, index+1);
                c[i]=0;
                rd[i+index]=0;
                ld[i-index+n-1]=0;
                v[index][i]='.';
            }
        }
    } 
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n, string (n, '.'));
        vector<bool> c(n, 0);
        vector<bool> rd(2*n-1, 0);
        vector<bool> ld(2*n-1, 0);
        fun(n, ans, v, c, rd, ld, 0);
        return ans;
    }
};