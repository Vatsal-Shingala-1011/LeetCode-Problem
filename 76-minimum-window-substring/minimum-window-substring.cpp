class Solution {
public:
    bool isPossible(const map<char, int>& m) {
        for (auto i : m) {
            if (i.second > 0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int len_s = s.length(), len_t = t.length();
        if (len_t > len_s) return ""; 

        map<char, int> m;
        for (int i = 0; i < len_t; i++) {
            m[t[i]]++;
        }

        int i = 0, j = 0;
        int minLen = INT_MAX;
        int start = 0;
        while (j < len_s) {
            if (m.find(s[j]) != m.end()) m[s[j]]--;

            while (isPossible(m)) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                if (m.find(s[i]) != m.end()) m[s[i]]++;
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
