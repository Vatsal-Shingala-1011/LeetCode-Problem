//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    int check(vector<vector<int> >& matrix, int i, int j, int row, int col){
        int cnt = 0;
            
        if(j - 1 >= 0){
            if(i - 1 >= 0){
                cnt += matrix[i - 1][j - 1] == 0;
            }
            if(i + 1 < row){
                cnt += matrix[i + 1][j - 1] == 0;
            }
            cnt += matrix[i][j - 1] == 0;
        }
        if(j + 1 < col){
            if(i - 1 >= 0){
                cnt += matrix[i - 1][j + 1] == 0;
            }
            if(i + 1 < row){
                cnt += matrix[i + 1][j + 1] == 0;
            }
            cnt += matrix[i][j + 1] == 0;
        }
        if(i - 1 >= 0){
            cnt += matrix[i - 1][j] == 0;
        }
        if(i + 1 < row){
            cnt += matrix[i + 1][j] == 0;
        }
        return (cnt > 0) && (cnt % 2 == 0);
    }
public:
    int Count(vector<vector<int> >& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j])
                    ans += check(matrix, i, j, row, col);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends