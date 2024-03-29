//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        void fun(int i, int n, string s, vector<string> &ans, string &sub){
            if(i<n){
                sub += s[i];
                fun(i+1,n,s,ans,sub);
                sub.pop_back();
                fun(i+1,n,s,ans,sub);
            }
            else{
                if(sub.size()>0){
		            ans.push_back(sub);
                }
            }
        }
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		    /*
		    vector<string> ans;
		    int n = s.size();
		    for(int num =0; num<(1<<n);num++){
		        string sub = "";
		        for(int i = 0;i<n;i++){
		            if(num & (1<<i)){
		                sub += s[i];
		            }
		        }
		        if(sub.size()>0){
		            ans.push_back(sub);
		        }
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		    
		    */
		    
		    vector<string> ans;
		    int n = s.size();
		    string sub = "";
		    fun(0,n,s,ans,sub);
		    sort(ans.begin(),ans.end());
		    return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends