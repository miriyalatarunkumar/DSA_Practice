class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /*
        if(rowIndex == 0)return {1};
        if(rowIndex == 1)return {1,1};
        vector<int> prev = {1,1};
        for(int i=2; i<=rowIndex; i++){
            vector<int> curr(i+1, 1);
            for(int j=1; j<i; j++){
                curr[j]=prev[j]+prev[j-1];
            }
            prev=curr;
        }
        return prev;
        */
        vector<int> A(rowIndex+1, 0);
        A[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    }
};