class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int r = query_row, g = query_glass;
        vector<double> prev(1,poured);
        for(int i=1; i<=r; i++){
            vector<double> curr(i+1, 0);
            for(int j=0; j<i; j++){
                double extra = prev[j]-1;
                if(extra>0){
                    curr[j] += 0.5 * extra;
                    curr[j+1] += 0.5 * extra;
                }
            }
            prev=curr;
        }
        return min((double)1,prev[g]);
    }
};