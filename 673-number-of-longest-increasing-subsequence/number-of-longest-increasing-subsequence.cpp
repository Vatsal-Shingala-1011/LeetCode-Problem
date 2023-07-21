// class Solution {
// public:
//     int solve(vector<int>& nums,int n,int i,int prev){
//         if(i==n) return 0;
//         int take=0;
//         //take if possible
//         if(nums[i]>prev){
//             take=1+solve(nums,n,i+1,nums[i]);
//         }
//         //not take
//         int nottake=solve(nums,n,i+1,prev);
//         return max(take,nottake);
//     }
//     int findNumberOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int,int> memo(n+1,)
//         return solve(nums,n,0,INT_MIN);
//     }
// };

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> size(n, 1);
        vector<int> ways(n, 1);

        int maxL = 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j] && size[j] + 1 > size[i]) {
                    size[i] = size[j] + 1;
                    ways[i] = ways[j];
                }
                else if(nums[i] > nums[j] && size[j] + 1 == size[i]) {
                    ways[i] += ways[j];
                }
                
                maxL = max(maxL, size[i]);
            }
        }
        int res = 0;
        for(int i=0; i<n; i++) {
            if(size[i] == maxL){
                res += ways[i];
            }
        }

        return res;
    }
};