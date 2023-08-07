class Solution {
private:
    int fun(vector<int> &coins, int amount, int i){
        if(amount == 0) return 0;
        if(i<0) return 1e9;
        int pick = 1e9;
        if(amount>=coins[i]) pick = 1+fun(coins, amount - coins[i], i);
        int npick = fun(coins, amount, i-1);
        return min(pick, npick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); 
        // initialize the dp array with an invalid number which is amount + 1 
        // because the maximum number of coins that we can use to form the amount is amount itself, by using 1 denomination. 
        dp[0] = 0; // no coin is needed to form amount 0
        for(int i=1; i<=amount; i++){
            for(auto &coin: coins){
                if(coin <= i){
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};