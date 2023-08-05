// class Solution {
// public:
//     int fun(int i,int n,vector<int>& memo){
//         if(i==n) return 1;
//         if(i==n-1) return 1;
//         if(memo[i]!=-1) return memo[i];

//         return memo[i]=fun(i+1,n,memo) + fun(i+2,n,memo);
//     }
//     int climbStairs(int n) {
//         vector<int> memo(n+1,-1);
//         return fun(0,n,memo);
//     }
// };

class Solution { //tabulation self 100%
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int> memo(n+1,-1);
        memo[1]=1;
        memo[2]=2;
        for(int i=3;i<=n;i++){
            memo[i]=memo[i-1]+memo[i-2];
        }
        return memo[n];
    }
};

