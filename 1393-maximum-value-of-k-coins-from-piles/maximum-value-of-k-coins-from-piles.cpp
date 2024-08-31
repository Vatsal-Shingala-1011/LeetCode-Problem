class Solution {
public:
int solve(vector<vector<int>>& piles, int i, int j, int n, int k,vector<vector<vector<int>>> &dp){
    if (i >= n || k == 0) {
        return 0;
    }

    if(dp[i][j][k] != -1) return dp[i][j][k];

    int m = piles[i].size();
    int inc = 0;


    if (j < m && k > 0) {
        inc = piles[i][j] + solve(piles, i, j + 1, n, k - 1, dp);
    }
    int exc = solve(piles, i + 1, 0, n, k, dp);

    return dp[i][j][k] = max(inc, exc);
}

int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    int i = n, j = piles[0].size();
    int lavda = 0;

    for(auto i:piles){
        if(lavda< i.size()) lavda = i.size();
    }

   vector<vector<vector<int>>> dp(i+1, vector<vector<int>>(lavda+1, vector<int>(k+1, -1)));

    return solve(piles, 0, 0, n, k, dp);
}

};