class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1], x2 = coordinates[1][0], y2 = coordinates[1][1];
        int isxZero = 1;
        for(auto it : coordinates){
            if(it[0]!= x1) isxZero = 0;
        }
        if ( isxZero == 1) return true;
        float m = (float)(y2 - y1) / (float)(x2 - x1);
        float c = (float) y1 - m*x1;
        for(int i = 2; i<coordinates.size();i++){
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if(y != (m*x)+c) return false;
        }
        return true;
    }
};