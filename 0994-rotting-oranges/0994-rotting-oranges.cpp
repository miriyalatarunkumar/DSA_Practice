class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};
        vector<vector<bool>> visited(m, vector<bool> (n, 0));
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int ans=-1;
        while(!q.empty()){
            ans++;
            int size = q.size();
            while(size>0){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                size--;
                for(int k=0; k<4; k++){
                    int I = i+row[k];
                    int J = j+col[k];
                    if(I>=0&&I<m&&J>=0&&J<n && !visited[I][J] && grid[I][J] == 1){
                        visited[I][J]=1;
                        q.push({I,J});
                    }
                }
            }
        }
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]) return -1;
            }
        }
        return ans==-1? 0:ans;
    }
};