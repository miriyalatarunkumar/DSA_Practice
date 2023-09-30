//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        /*
        vector<vector<int>> temp = matrix;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<bool>isoner(r,0), isonec(c,0);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(temp[i][j]){
                    if(!isoner[i]){
                        for(int k=0; k<c; k++){
                            matrix[i][k]=1;
                        }
                        isoner[i]=1;
                    }
                    if(!isonec[j]){
                        for(int k=0; k<r; k++){
                            matrix[k][j]=1;
                        }
                        isonec[j]=1;
                    }
                }
            }
        }
        */
        int r = matrix.size();
        int c = matrix[0].size();
        vector<bool>isoner(r,0), isonec(c,0);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j]){
                    isoner[i]=1;
                    isonec[j]=1;
                }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(isoner[i] || isonec[j]){
                    matrix[i][j]=1;
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends