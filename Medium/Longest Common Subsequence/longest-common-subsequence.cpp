//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int solve(int n1,int m1,int n,int m, string& s1, string& s2,vector<vector<int>>& memo){
        if(n1==n || m1==m){
            return 0;
        }
        if(memo[n1][m1]!=-1){
            return memo[n1][m1];
        }
        int ans=0;
        if(s1[n1]==s2[m1]){//if possible then always take
            ans=1+solve(n1+1,m1+1,n,m,s1,s2,memo);
        }
        else{
            ans=max(solve(n1+1,m1,n,m,s1,s2,memo),solve(n1,m1+1,n,m,s1,s2,memo));
        }
        return memo[n1][m1]=ans;
    }
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return solve(0,0,n,m,s1,s2,memo);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends