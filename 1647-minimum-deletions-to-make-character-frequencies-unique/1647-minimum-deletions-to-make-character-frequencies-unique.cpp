class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(auto it: s)freq[it-'a']++;
        unordered_set<int>st;
        int ans =0;
        for(auto it: freq){
            while(it>0 && st.count(it)){
                ans++;
                it--;
            }
            if(it>0)st.insert(it);
        }
        return ans;
    }
};