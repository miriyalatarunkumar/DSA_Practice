//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
        bool check(int i, int j, string s){
            int left = i;
            int right = j-1;
            while (left < right){
                if (s[left] != s[right]) return false;
                left++;
                right--;
            }           
            return true;
        }
        
    public:
        string longestPalin (string s) {
            // code here
            
            // Brute Force
            // no. of substrings = n(n+1)/2 => O(n^2)
            // For each substring, we are doing palindrome check which takes O(n)
            // => Total T.C.: O(n^3)
            // Because the problem wants the longest palindrome, we can start by checking the longest-length substrings and iterate toward the shorter-length substrings. This way, the first time we find a substring that is a palindrome, we can immediately return it as the answer.
            
            for (int length = s.length(); length > 0; length--) {
                for (int start = 0; start <= s.length() - length; start++) {
                    if (check(start, start + length, s)) {
                        return s.substr(start, length);
                    }
                }
            }
            
            return "";
        }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends