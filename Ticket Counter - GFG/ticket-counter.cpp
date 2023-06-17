//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        deque<int>q; int count = K, flag = 0;
        while(N) q.push_front(N--);
        while(q.size()!=1){
            if(!flag){
                q.pop_front();
                K--;
                if(!K){
                    K=count;
                    flag =1;
                }
            }
            else{
                q.pop_back();
                K--;
                if(!K){
                    K=count;
                    flag =0;
                }
            }
        }
        return q.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends