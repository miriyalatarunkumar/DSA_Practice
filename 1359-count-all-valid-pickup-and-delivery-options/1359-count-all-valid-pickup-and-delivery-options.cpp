class Solution {
public:
    int countOrders(int n) {
        long long int mod = 1e9+7;
        long long int result = 1;
        int slots = 2*n;
        while(slots){
            long long int valid_choices = (slots*(slots-1))/2;
            result = (result*valid_choices)%mod;
            slots-=2;
        }
        return result;
    }
};