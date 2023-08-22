//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> rowsum, colsum;
        for(auto row : matrix){
            int sum=0;
            for(auto it: row){
                sum+=it;
            }
            rowsum.push_back(sum);
        }
        for(int j=0; j<n; j++){
            int sum=0;
            for(int i=0; i<n; i++){
                sum+=matrix[i][j];
            }
            colsum.push_back(sum);
        }
        int maxi = INT_MIN;
        for(auto it:rowsum) maxi = max(maxi,it);
        for(auto it:colsum) maxi = max(maxi,it);
        int ans = 0;
        for(auto it:rowsum) ans += maxi-it;
        for(auto it:colsum) ans += maxi-it;
        return ans/2;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends