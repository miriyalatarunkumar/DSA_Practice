class Solution {
public:
    int partitionString(string s) {
        //if(s == "") return 0;
        int ans = 1;
        unordered_set<char> st;
        for(int i = 0; i< s.size(); i++){
            if(st.count(s[i])){
                ans++;
                st.clear();
                st.insert(s[i]);
            }
            st.insert(s[i]);
        }
        return ans;
    }
};