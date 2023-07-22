class Solution {
double dp[26][26][101];
double f(int n,int k,int i,int j){
    if(k==0) return 1;
    if(dp[i][j][k]>=0) return dp[i][j][k];
    int dx[8] = {2,2,1,1,-1,-1,-2,-2};
    int dy[8] = {1,-1,2,-2,2,-2,-1,+1};
    double cnt = 0;
    for(int p=0;p<8;p++){
        int ni = dx[p] + i;
        int nj = dy[p] + j;
        if(ni>=0 && ni<n && nj<n && nj>=0){
            cnt+=f(n,k-1,ni,nj);
        }
    }
    return dp[i][j][k] =  cnt;
}
public:
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,-1,sizeof(dp));
        return f(n,k,row,column)/pow(8,k);
    }
};