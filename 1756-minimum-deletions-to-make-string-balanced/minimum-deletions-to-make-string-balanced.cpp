// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int res = 0, count = 0;
//         for (char c : s){
//             if (c == 'b') count++;
//             else if (count){
//                 res++;
//                 count--;
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n=s.length();
//         int count=0;
//         stack<char> st;
//         st.push(s[0]);
    
//         for(int i=1;i<n;i++){
//             if(!st.empty() && (st.top()=='b' && s[i]=='a')){
//                 st.pop();
//                 count++;
//             }
//             else{
//                 st.push(s[i]);
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        int countB = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'b') {
                dp[i] = dp[i - 1];  // No need to delete, just carry forward the previous state
                countB++;
            } else { // s[i - 1] == 'a'
                dp[i] = min(dp[i - 1] + 1, countB);  // Either delete this 'a' or delete all previous 'b's
            }
        }
        
        return dp[n];
    }
};
