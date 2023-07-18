//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(string str1,string str2,int i,int j,vector<vector<int>>& memo){
        if(i==str1.length() || j==str2.length()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(str1[i]==str2[j]) return memo[i][j]=1+solve(str1,str2,i+1,j+1,memo);
        else{
            return memo[i][j]=max(solve(str1,str2,i+1,j,memo),solve(str1,str2,i,j+1,memo));
        }
    }
    int longestPalinSubseq(string str) {
        int n=str.length();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        string str2=str;
        reverse(str2.begin(),str2.end());
        return solve(str,str2,0,0,memo);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends