class Solution {
public:
    void dfs(int i,int j,int m, int n,vector<vector<char>>& grid,vector<vector<bool>> & vis){
        vis[i][j]=true;
        if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]=='1'){
            dfs(i-1,j,m,n,grid,vis);
        }
        if(i+1<m && !vis[i+1][j] && grid[i+1][j]=='1'){
            dfs(i+1,j,m,n,grid,vis);
        }
        if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]=='1'){
            dfs(i,j-1,m,n,grid,vis);
        }
        if(j+1<n && !vis[i][j+1] && grid[i][j+1]=='1'){
            dfs(i,j+1,m,n,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,m,n,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};