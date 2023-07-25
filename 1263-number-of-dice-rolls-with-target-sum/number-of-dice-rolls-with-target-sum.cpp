class Solution {
public:
    int mod=1e9+7;
    int solve(int index,int n,int k,long long target,vector<vector<long long>>& dp){
        if(index==n && target==0) return 1;
        if(index==n) return 0;
        if(dp[index][target]!=-1) return dp[index][target];
        long long ans=0;
        for(int i=1;i<=k;i++){
            if(target>=i){
                ans=(((ans%mod)+(solve(index+1,n,k,target-i,dp)%mod))%mod);
            }
        }
        return dp[index][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
        return solve(0,n,k,target,dp);
    }
};