class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid, vector<vector<bool>>& vis,int& ans){
        vis[i][j]=true;
        if(i-1>=0 && grid[i-1][j]==1 && !vis[i-1][j]){
            dfs(i-1,j,n,m,grid,vis,ans);
        }
        else{//i-1<0 or grid[i-1][j]==0
            if(i-1>=0 && grid[i-1][j]==1 && vis[i-1][j]){

            }else{ans++;}
        }
        if(i+1<n && grid[i+1][j]==1&& !vis[i+1][j]){
            dfs(i+1,j,n,m,grid,vis,ans);
        }
        else{
            if(i+1<n && grid[i+1][j]==1&& vis[i+1][j]){

            }else{ans++;}
        }
        if(j-1>=0 && grid[i][j-1]==1&& !vis[i][j-1]){
            dfs(i,j-1,n,m,grid,vis,ans);
        }
        else{
            if(j-1>=0 && grid[i][j-1]==1&& vis[i][j-1]){

            }else{ans++;}
        }
        if(j+1<m && grid[i][j+1]==1&& !vis[i][j+1]){
            dfs(i,j+1,n,m,grid,vis,ans);
        }
        else{
            if(j+1<m && grid[i][j+1]==1&& vis[i][j+1]){

            }else{ans++;}
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,n,m,grid,vis,ans);
                }
            }
        }
        return ans;
    }
};