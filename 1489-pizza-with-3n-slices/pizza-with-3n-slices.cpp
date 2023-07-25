class Solution {
public:
    int solve(int index,int endindex,vector<int>& slices,int n,vector<vector<int>>& memo){
        if(n==0||index>=endindex) return 0;
        if(memo[index][n]!=-1) return memo[index][n];
        int take=slices[index]+solve(index+2,endindex,slices,n-1,memo);
        int nottake=solve(index+1,endindex,slices,n,memo);
        return memo[index][n]=max(take,nottake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        vector<vector<int>> memo1(k,vector<int>((k/3)+1,-1));
        int case1=solve(0,k-1,slices,k/3,memo1);
        vector<vector<int>> memo2(k,vector<int>((k/3)+1,-1));
        int case2=solve(1,k,slices,k/3,memo2);
        return max(case1,case2);
    }
};