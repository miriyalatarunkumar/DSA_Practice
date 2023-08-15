//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        // by kadane algorithm
        int c1=0,c0=0,mx0=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                c0++;
                mx0=max(mx0,c0);
            }
            else
            {
                c1++; 
                c0--; 
                
            }
            if(c0<0)c0=0;
            
        }
        return mx0+c1;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends