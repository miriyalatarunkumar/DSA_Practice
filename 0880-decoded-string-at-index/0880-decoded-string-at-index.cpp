class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long length = 0;
        int n = s.size();

        // First pass to compute the length of the decoded string.
        for (char c : s) {
            if (isdigit(c)) { 
                length *= (c - '0');
            } else {
                length++;
            }
        }

        // Working backwards to find the kth character.
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            k %= length;
            if (k == 0 && isalpha(c)) {
                return string(1, c);
            }
            if (isdigit(c)) {
                length /= (c - '0');
            } else {
                length--;
            }
        }
        return "";
    }
};
