class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { //valid not necessarily solvable
        const int n = 9;
        bool row[n][n] = {false};
        bool col[n][n] = {false};
        bool subGrid[n][n] = {false};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.') continue;
                int idx = board[i][j] - '1';
                int gridNum = (i/3) * 3 + (j/3);
                if(row[i][idx] || col[j][idx] || subGrid[gridNum][idx]){
                    return false;
                }
                row[i][idx] = true;
                col[j][idx] = true;
                subGrid[gridNum][idx] = true;
            }
        }
        return true;
    }
};