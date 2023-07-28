class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (len == 1) dp[i][j] = nums[i];
                else {
                    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
// class Solution {//done
// public:
//     int solve(vector<int>& nums, int sum1 , int sum2, bool turn ,int i, int j ){ //done
//         if(i>j){
//             if(sum1>=sum2) return 1;   
//             return 0;
//         }
//         if(turn) return solve(nums,sum1+nums[i],sum2,false,i+1,j) || solve(nums,sum1+nums[j],sum2,false,i,j-1);
//         else
//            return solve(nums,sum1,sum2+nums[i],true,i+1,j) && solve(nums,sum1,sum2+nums[j],true,i,j-1);
//     }
//     bool PredictTheWinner(vector<int>& nums) {
//         return solve(nums,0,0,true,0,nums.size()-1);
//     }
// };


// class Solution { //done
// public:
//     int solve(vector<int>& nums, bool turn ,int i, int j ){
//         if(i>j) return 0;
//         if(turn)return max(nums[i]+solve(nums,false,i+1,j),nums[j]+solve(nums,false,i,j-1));
//         else
//            return min(solve(nums,true,i+1,j),solve(nums,true,i,j-1));
//     }
//     bool PredictTheWinner(vector<int>& nums) {    
//         int totalSum=0;
//         for(int i=0;i<nums.size();i++){
//             totalSum+=nums[i];
//         }
//         int sum1= solve(nums,true,0,nums.size()-1); 
//         int sum2=totalSum-sum1;  
//         return sum1>=sum2;
//     }
// };



