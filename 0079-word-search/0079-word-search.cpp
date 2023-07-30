class Solution {
private:
    bool fun(vector<vector<char>>& board, string word, int m, int n, vector<vector<bool>> &visited, int i, int j, int index, vector<int> &dr, vector<int> &dc){
        if(index == word.size()) return true;
        for(int k = 0; k<4; k++){
            int I = i+dr[k];
            int J = j+dc[k];
            if(I>=0 && I <m && J>=0 && J<n && !visited[I][J] && board[I][J]==word[index]){
                visited[I][J]=1;
                if(fun(board, word, m, n, visited, I, J, index+1, dr, dc)) return true;
                visited[I][J] =0;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=1;
                    if(fun(board, word, m, n, visited, i, j, 1, dr, dc)) return true;
                    visited[i][j]=0;
                }
            }
        }
        return false;
    }
};