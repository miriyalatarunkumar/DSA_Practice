//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        if(N==1) return 0;
        long long ans = 1;
        for(long long i=2; i*i<=N; i++){
            if(N%i==0){
                if(N/i==i)ans+=i;
                else ans = ans + i + N/i;
                if (ans > N) return 0;
            }
        }
        return ans==N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends