class Solution {
public:
    int longestValidParentheses(string s) { //self
        int n = s.length();
        int o = 0, c = 0, ans = 0, temp = 0;
        // Left to right pass
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                o++;
            } else {
                c++;
            }
            if (o == c) {
                ans = max(ans, 2 * c);
            } else if (c > o) {
                o = c = 0;
            }
        }
        o = c = 0;
        // Right to left pass
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                o++;
            } else {
                c++;
            }
            if (o == c) {
                ans = max(ans, 2 * o);
            } else if (o > c) {
                o = c = 0;
            }
        }

        return ans;
    }
};
