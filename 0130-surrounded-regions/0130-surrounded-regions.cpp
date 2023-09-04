class Solution {
    void dfs(int n, int m, int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &visited, vector<int> &row, vector<int> &col){
        visited[i][j]=1;
        for(int k=0; k<4; k++){
            int r = i+row[k];
            int c = j+col[k];
            if(r>=0 && r<n && c>=0 && c<m && !visited[r][c] && mat[r][c]=='O') dfs(n, m, r, c, mat, visited, row, col);
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};
        for(int i=0; i<m; i++){
            if(mat[0][i]=='O') dfs(n, m, 0, i, mat, visited, row, col);
            if(mat[n-1][i]=='O') dfs(n, m, n-1, i, mat, visited, row, col);
        }
        for(int i=0; i<n; i++){
            if(mat[i][0]=='O') dfs(n, m, i, 0, mat, visited, row, col);
            if(mat[i][m-1]=='O') dfs(n, m, i, m-1, mat, visited, row, col);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && mat[i][j] == 'O') mat[i][j]='X';
            }
        }
    }
};