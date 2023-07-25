class Solution {
public:
    int solve(vector<int>& satisfaction, int index,int time,vector<vector<int>>& memo){
        if(index==satisfaction.size()) return 0;
        if(memo[index][time]!=-1) return memo[index][time];
        int include=satisfaction[index]*(time+1) + solve(satisfaction,index+1,time  +1,memo);
        int exclude=solve(satisfaction,index+1,time,memo);
        return memo[index][time]=max(include,exclude);
    }
    int solvetab(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<vector<int>> memo(n+1,vector<int> (n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j<=i-1){
                    memo[i][j]=max(memo[i-1][j-1]+j*satisfaction[i-1],memo[i-1][j]);
                }
                else{
                    memo[i][j]=memo[i-1][j-1]+j*satisfaction[i-1];
                }
            }
        }
        int maxi=0;
            for(int i=0;i<=n;i++){
                if(memo[n][i]>maxi)maxi=memo[n][i];
            }
        return maxi;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // vector<vector<int>> memo(n+1,vector<int> (n+1,-1));
        // return solve(satisfaction,0,0,memo);
        return solvetab(satisfaction);
    }
};








