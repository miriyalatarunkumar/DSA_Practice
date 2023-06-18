//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        // Your code here
        //Standard approach for Modifing arrays in O(1)
        /*
        *use a prime to multiply and store old / new values
        *add the new / old part to the same number
        *now, old value can be accessed with division ( / ) and new value can be accessed by mod ( % )
        */
        int m = 1e9 + 7;  // prime
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] + (arr[arr[i]]%m) * m;
                     // old          // new
        }
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i]/m;
        }
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends