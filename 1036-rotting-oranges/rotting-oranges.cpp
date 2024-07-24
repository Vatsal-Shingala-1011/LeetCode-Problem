class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int time=0;
        while(!q.empty()){
            int size=q.size();
            bool update=false;
            while(size){
                auto front=q.front();
                q.pop();
                int i=front.first,j=front.second;
                vector<int> r={1,0,-1,0};
                vector<int> c={0,1,0,-1};
                for(int ii=0;ii<4;ii++){
                    if(i+r[ii]>=0 && i+r[ii]<n && j+c[ii]>=0 && j+c[ii]<m && grid[i+r[ii]][j+c[ii]]==1){
                        grid[i+r[ii]][j+c[ii]] = 2;
                        q.push({i+r[ii],j+c[ii]});
                        update=true;
                    }
                }
                size--;
            }
            if(update) time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};