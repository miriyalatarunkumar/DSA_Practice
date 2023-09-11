class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1)return 0;
        int ans = 1;
        for(int i=2; i*i<=num; i++){
            if(num%i==0){
                if(i==num/i)ans+=i;
                else ans = ans + i + num/i;
                if(ans>num)return 0;
            }
        }
        return ans==num;
    }
};