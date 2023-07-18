//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solvememo(string& str1, string& str2, int i, int j,vector<vector<int>>& dp){//self
        if(i==str1.length() || j==str2.length()) return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans;
        if(str1[i]==str2[j] && i!=j) ans=1+solvememo(str1,str2,i+1,j+1,dp);
        else{
             ans=max(solvememo(str1,str2,i,j+1,dp), solvememo(str1,str2,i+1,j,dp));
        }
        return dp[i][j] = ans;
    }
    
    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveTab(string& str1, string& str2) {
        int n = str1.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int ans = 0;
                if(str1[i] == str2[j] && i != j) {
                    ans = 1 + dp[i+1][j+1];
                } else {
                    ans = max( dp[i][j+1], dp[i+1][j] );
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    
    //Time Complexity => O(n^2)
    //Space Complexity => O(n)
    // Space Optimization
    int solveSO(string& str1, string& str2) {
        int n = str1.length();
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int ans = 0;
                if(str1[i] == str2[j] && i != j) {
                    ans = 1 + next[j+1];
                } else {
                    ans = max( curr[j+1], next[j] );
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    
	public:
		int LongestRepeatingSubsequence(string str){
		  // Memoization
		  int n = str.length();
		  vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
		  return solvememo(str, str, 0, 0, dp);
		  
		  
		  //// Tabulation
		  //return solveTab(str, str);

		  
		  // Space Optimization
		  //return solveSO(str, str);
		  
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends