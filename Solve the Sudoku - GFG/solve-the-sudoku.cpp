//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    private:
    // Using array to keep track of possible numbers for each row, col, and block
    bool row[9][10], col[9][10], block[3][3][10];
    
    public:
    bool SolveSudoku(int grid[N][N])  
    { 
        // Initializing the row, col, and block arrays
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(block, false, sizeof(block));
    
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                int num = grid[i][j];
                if (num != 0) {
                    row[i][num] = col[j][num] = block[i/3][j/3][num] = true;
                }
            }
        }
        return solve(grid, 0, 0);
    }
    
    bool solve(int grid[N][N], int i, int j){
        // Base case - reached the end of grid
        if (i == 9) {
            return true;
        }
        
        // If reached the end of the row, move to the next row
        if (j == 9) {
            return solve(grid, i + 1, 0);
        }
        
        // If cell is not empty, move to the next cell
        if (grid[i][j] != 0) {
            return solve(grid, i, j + 1);
        }
    
        // Try numbers from 1 to 9 in the empty cell
        for (int num = 1; num <= 9; num++) {
            // Check whether it is safe to put the number in the cell or not
            if (!row[i][num] && !col[j][num] && !block[i/3][j/3][num]) {
                grid[i][j] = num;
                row[i][num] = col[j][num] = block[i/3][j/3][num] = true;
    
                // If we can solve the Sudoku by putting num in the current cell
                if (solve(grid, i, j + 1)) {
                    return true;
                }
    
                // If we can't proceed with this solution
                // remove the number from the current cell
                grid[i][j] = 0;
                row[i][num] = col[j][num] = block[i/3][j/3][num] = false;
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid(int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<grid[i][j]<<" ";
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
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends