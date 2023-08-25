class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        if(image[sr][sc]==color)return image;
        int prevcolor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};
        while(!q.empty()){
            int I = q.front().first;
            int J = q.front().second;
            q.pop();
            for(int k =0; k<4; k++){
                int i = I + row[k];
                int j = J + col[k];
                if(i>=0 && i<m && j>=0 && j<n && image[i][j] == prevcolor){
                    q.push({i,j});
                    image[i][j]=color;
                }    
            }
        }
        return image;
    }
};