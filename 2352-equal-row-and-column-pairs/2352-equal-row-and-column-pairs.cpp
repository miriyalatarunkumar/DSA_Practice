class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        /*
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
        */
        
        vector<vector<int>> grid2=grid;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=i; j<grid[0].size(); j++)
            {
                swap(grid[i][j],grid[j][i]);
            }
        }
        int ans=0;
        for(int i=0;i<grid2.size(); i++)
        {
            for(int j=0;j<grid.size(); j++)
            {
                if(grid2[i]==grid[j]) // comparing the row vectors in two matrices
                    ans++;
            }
        }
        return ans;
    }
};