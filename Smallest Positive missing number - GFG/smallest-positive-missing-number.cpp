//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
         //Optimal approach
         
         //Step 1 : placing all the valid elements to its correct position
         // elements : 0  -10  1  3  -20  ---> 1  -10  3  0  -20
         // index    : 0   1   2  3   4   ---> 0   1   2  3    4
         
         for(int i = 0; i<n; i++){
             
            int val = arr[i];
             
            if(arr[i] > 0 && arr[i] <= n){
                int posi = val - 1;
                
                if(arr[posi] != val){
                    swap(arr[posi], arr[i]);
                    i--;
                }
            }
         }
         
         //now the first no. we encounter which is not in its correct position we return the ans
         for(int i = 1; i<=n; i++){
             if(i != arr[i-1]){
                 return i;
             }
         }
         
         //if all the element in its correct posiiton then we the next smaller +ve int will be N+1
         return n+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends