//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long p) {
        /*
        // GOT TLE
        int count = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 0; j+i<=n; j++){
                long long product = 1;
                bool flag = 0;
                for(int k = j; k<j+i; k++){
                    product *= a[k];
                    if(product>= p){
                        flag = 1;
                        break;
                    }
                }
                if(!flag) count++;
            }
        }
        return count;
        */
        
        /*
        
        //The idea is to keep a max_product_window whose size is less than 'k';
        //Every time we shift window by adding a new number on the right (j), if the product is greater than 'k', then try to reduce numbers on the left (i), until the subarray product fit in the window (subarray could be empty).
        //Each step introduces x new subarrays, where x is the size of the current window j - i + 1.
        
         if(p == 0) return 0;
        int ans = 0;
        long long product = 1;
        for(int i = 0, j = 0; j < a.size(); j++)
        {
            product *= a[j];
            while(i <= j && product >= p)
            {
                product /= a[i];
                i++;
            }
            ans += j - i + 1; // all subarrays from i to j.(which are not yet included)
        }
        return ans;
        */
        
        int i=0,j=0;
        long long ans=1;
        int cnt=0;
        while(i<n && j<n)
        {
            ans*=a[j];
            if(ans<p)
            {
                cnt++;
                j++;
                if(j==n)
                {
                    i++;
                    j=i;
                    ans=1;
    
                }
            }
            else
            {
                i++;
                j=i;
                ans=1;
            }
        }
        return cnt;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends