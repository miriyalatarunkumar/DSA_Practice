//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{   private:
    int fun(int n, int ind, int a[], int prev, vector<vector<int>> &dp){
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        if(ind == n-1){
            if(a[ind] > a[prev]) return 1;
            return 0;
        }
        int pick=0, npick=0;
        if(prev == -1 || a[ind]>a[prev]) pick = 1+fun(n, ind+1, a, ind, dp);
        npick = fun(n, ind+1, a, prev, dp);
        return dp[ind][prev+1] = max(pick, npick);
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       /*
       vector<vector<int>> dp(n, vector<int> (n+1, -1));
       return fun(n, 0, a, -1, dp);
       */
       vector<int> tails(n, 0);
        int length = 0;

        for (int i = 0; i < n; i++) {
            int left = 0, right = length;

            // Binary search to find the first position "left" where a[i] is less than tails[left]
            while (left != right) {
                int mid = (left + right) / 2;
                if (tails[mid] < a[i])
                    left = mid + 1;
                else
                    right = mid;
            }

            tails[left] = a[i];
            if (left == length) length++;
        }

        return length;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends