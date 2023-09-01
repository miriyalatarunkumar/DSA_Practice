class Solution {
    int count(int i){
        int ans = 0;
        while(i){
            if(i & 1)ans++;
            i=i/2;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++) ans[i]=count(i);
        return ans;
    }
};