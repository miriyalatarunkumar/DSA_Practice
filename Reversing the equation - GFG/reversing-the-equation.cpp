//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans="";
            int i = 0;
            while(i<s.size()){
                string num = "";
                while (s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && i<s.size()){
                    num.push_back(s[i]);
                    i++;
                }
                if(i<s.size()) ans = s[i]+num+ans;
                else ans = num+ans;
                i++;
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends