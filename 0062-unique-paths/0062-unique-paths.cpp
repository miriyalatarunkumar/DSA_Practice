class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0), curr(n,1);
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                curr[j]=curr[j-1]+prev[j];
            }
            prev=curr;
        }
        return prev[n-1];
    }
};