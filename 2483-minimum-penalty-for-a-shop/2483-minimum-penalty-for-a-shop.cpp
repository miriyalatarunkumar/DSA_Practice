class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pre_N(n+1, 0);
        vector<int> post_Y(n+1, 0);
        int pre = 0;
        for(int i=0; i<n+1; i++){
            pre_N[i]=pre;
            if(customers[i]=='N') pre++; 
        }
        int post = 0;
        for(int i=n-1; i>=0; i--){
            post_Y[i] = customers[i]=='Y' ? ++post : post; 
        }
        int ans = 0, maxi = 1e9;
        for(int i=0; i<=n; i++){
            if(pre_N[i]+post_Y[i]<maxi){
                maxi = pre_N[i]+post_Y[i];
                ans = i;
            }
        }
        return ans;
    }
};