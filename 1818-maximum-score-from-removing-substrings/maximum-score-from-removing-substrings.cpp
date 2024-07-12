class Solution {
public:
    int maximumGain(string str, int x, int y) {
        stack<char> s;
        int ans = 0;
        
        if (x > y) {
            for (auto ch : str) {
                if (ch == 'a') {
                    s.push(ch);
                } else if (ch == 'b' && !s.empty() && s.top() == 'a') {
                    s.pop();
                    ans += x;
                } else {
                    s.push(ch);
                }
            }
            stack<char> t;
            while (!s.empty()) {
                char top = s.top();
                s.pop();
                if (top == 'b') {
                    if (!t.empty() && t.top() == 'a') {
                        t.pop();
                        ans += y;
                    } else {
                        t.push(top);
                    }
                } else {
                    t.push(top);
                }
            }
        } else {
            for (auto ch : str) {
                if (ch == 'b') {
                    s.push(ch);
                } else if (ch == 'a' && !s.empty() && s.top() == 'b') {
                    s.pop();
                    ans += y;
                } else {
                    s.push(ch);
                }
            }
            stack<char> t;
            while (!s.empty()) {
                char top = s.top();
                s.pop();
                if (top == 'a') {
                    if (!t.empty() && t.top() == 'b') {
                        t.pop();
                        ans += x;
                    } else {
                        t.push(top);
                    }
                } else {
                    t.push(top);
                }
            }
        }

        return ans;
    }
};
