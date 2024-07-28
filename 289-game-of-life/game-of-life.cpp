class Solution {
public:
    void check(int i, int j, vector<vector<int>>& board, vector<vector<int>>& ans){
       int n=board.size(),m=board[0].size(); 
        vector<int> row = {1,1,1,0,0,-1,-1,-1};
        vector<int> col = {-1,0,1,-1,1,-1,0,1};
        int ones=0;
        for(int k=0;k<8;k++){
            int r=i+row[k],c=j+col[k];
            if(r>=0 && r<n && c>=0 && c<m && board[r][c]==1) ones++;
        }
        if(board[i][j]==1 && (ones>3 || ones<2)) ans[i][j]=0;
        if(board[i][j]==0 && ones==3) ans[i][j]=1;

    }
    void gameOfLife(vector<vector<int>>& board) {
       int n=board.size(),m=board[0].size(); 
       vector<vector<int>> ans=board;
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                check(i,j,board,ans);
            }
       }
       board=ans;
    }
};