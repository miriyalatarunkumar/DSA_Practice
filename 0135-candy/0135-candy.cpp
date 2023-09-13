class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // initially, give 1 candy to everyone

        // Traverse from left and assign candies depending on left neighbors
        for(int i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        // Traverse from right to adjust candies depending on right neighbors
        for(int i=n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};
