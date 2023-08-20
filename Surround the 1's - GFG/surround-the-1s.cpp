//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    int countzero(int i, int j, vector<vector<int> >& matrix, int n, int m){
        vector<int> row = {-1,-1,-1,0,0,1,1,1};
        vector<int> col = {-1,0,1,-1,1,-1,0,1};
        int cnt=0;
        for(int k=0; k<8; k++){
            int I = i+row[k];
            int J = j+col[k];
            if(I>=0 && I<n && J>=0 && J<m && matrix[I][J] == 0) cnt++;
        }
        return cnt;
    }
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!matrix[i][j]) continue;
                int zerosAround = countzero(i, j, matrix, n, m);
                if(zerosAround > 0 && zerosAround % 2 == 0) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends