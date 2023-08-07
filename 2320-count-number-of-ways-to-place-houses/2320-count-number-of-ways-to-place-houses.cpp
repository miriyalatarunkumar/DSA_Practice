class Solution {
public:
    int countHousePlacements(int n) {
        int mod = 1e9+7;
        long long prev1 = 0; // putting house at index 1
        long long prev2 = 0;
        for(int i=1; i<=n; i++){
            long long pick = 1 + prev2;
            long long npick = prev1;
            long long curr = (pick + npick) % mod; 
            prev2 = prev1;
            prev1 = curr;
        }
        prev1 = (prev1 + 1) % mod; // no house at index 1
        return (prev1 * prev1) % mod;
    }
};
