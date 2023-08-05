//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
    void fun(string &s, vector<string> &ans, int index){
        if(index==s.length()){
            ans.push_back(s);
            return;
        }
        for(int i= index; i<s.length(); i++){
            swap(s[index], s[i]);
            fun(s, ans, index+1);
            swap(s[index], s[i]);
        }
    }
public:
    //Complete this function
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        fun(S, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends