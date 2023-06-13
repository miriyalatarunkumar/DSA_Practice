class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0,k,r;
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(k =0, r = 0; k<n && r<n; k++, r++){
                    if(grid[i][k] != grid[r][j]) break;
                }
                if(k==n && r == n) ans++;
            }
        }
        return ans;
    }
};