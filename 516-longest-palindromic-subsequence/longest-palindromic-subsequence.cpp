class Solution{
  public:
    int solve(string str1,string str2,int i,int j,vector<vector<int>>& memo){//memoization
        if(i==str1.length() || j==str2.length()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(str1[i]==str2[j]) return memo[i][j]=1+solve(str1,str2,i+1,j+1,memo);
        else{
            return memo[i][j]=max(solve(str1,str2,i+1,j,memo),solve(str1,str2,i,j+1,memo));
        }
    }
    int solveTab(string& str1, string& str2) { //can do space optimum also
        int n = str1.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=1;i<=n;i++) {
            for(int j=1; j<=n;j++) {
                int ans=0;
                if(str1[i-1]==str2[j-1]) {
                    ans = 1 + dp[i-1][j-1];
                } else {
                    ans = max( dp[i][j-1], dp[i-1][j] );
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string str) {
        int n=str.length();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        string str2=str;
        reverse(str2.begin(),str2.end());
        // return solve(str,str2,0,0,memo);
        return solveTab(str,str2);
    }
};