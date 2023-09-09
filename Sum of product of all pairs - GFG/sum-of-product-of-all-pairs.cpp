//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int productOfPairs(int N, vector<int> A) {
        // code here
        int mod=1e9+7;
        long long sum=0;
        for(int i=0;i<N;i++)  sum+=A[i];
        int ans=0;
        for(int i=0;i<N-1;i++)
        {
            sum-=A[i];
            ans=(ans+(A[i]*sum))%mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (auto &u : A) cin >> u;
        Solution ob;
        cout << ob.productOfPairs(N, A) << "\n";
    }
}
// } Driver Code Ends