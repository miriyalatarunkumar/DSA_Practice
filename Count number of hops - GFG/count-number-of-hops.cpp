//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long mod = 1e9+7;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;
        
        long long prev1 = 1;
        long long prev2 = 2;
        long long prev3 = 4;
        
        for(int i = 4; i <= n; i++)
        {
            long long current = (prev1 + prev2 + prev3) % mod;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = current;
        }
        
        return prev3;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends