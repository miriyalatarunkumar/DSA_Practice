class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0,k=0;
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(k =0; k<n; k++){
                    if(grid[i][k] != grid[k][j]) break;
                }
                if(k==n) ans++;
            }
        }
        return ans;
    }
};