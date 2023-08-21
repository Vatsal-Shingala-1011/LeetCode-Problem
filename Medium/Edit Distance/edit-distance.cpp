//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {//self
        if (i == s.length()) return t.length() - j;
        if (j == t.length())return s.length() - i;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) {
            return dp[i][j] = solve(i + 1, j + 1, s, t, dp);
        } else {
            int insertOp = 1 + solve(i, j + 1, s, t, dp);    // Insert in s
            int deleteOp = 1 + solve(i + 1, j, s, t, dp);    // Delete in s
            int replaceOp = 1 + solve(i + 1, j + 1, s, t, dp); // Replace in s

            return dp[i][j] = min({insertOp, deleteOp, replaceOp});
        }
    }
    int editDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, s, t, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends