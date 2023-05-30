class Solution {
private:
    int newnum(int n){
        int sum =0;
        while(n){
            sum+= (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        if(n == 1) return 1;
        unordered_set<int> s;
        s.insert(n);
        int num = newnum(n);
        while(s.find(num)==s.end()){
            s.insert(num);
            num = newnum(num);
        }
        if(num==1 ) return 1;
        return 0;
    }
};