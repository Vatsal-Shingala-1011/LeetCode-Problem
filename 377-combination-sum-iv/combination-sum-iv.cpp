class Solution {
public:
    int solve(vector<int>& nums, int target)
    {
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        int ans=0;
        int size=nums.size();
        for(int i=0;i<size;i++){
            ans=1+solve(nums,target-nums[i]);
        }
        return ans;
    }

    int solvememo(vector<int>& nums, int target,vector<int>& memo)
    {
        if(target==0) return 1;
        if(target<0) return 0;
        if(memo[target]!=-1) return memo[target];
        int ans=0;
        int size=nums.size();
        for(int i=0;i<size;i++){
            ans+=solvememo(nums,target-nums[i],memo);
        }
        memo[target]=ans;
        return  memo[target];
    }
    int solvetab(vector<int>& nums, int target){ //self
        vector<int> memo(target+1,0);  //ans not fit in 32 bit
        int n=nums.size();             // ninja gives correct ans
        memo[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                if(i-nums[j]>=0 ){
                    memo[i]+= memo[i-nums[j]];
                }
            }
        }
        return memo[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target+1,-1);
        // return solvetab(nums,target);
        return solvememo(nums,target,memo);
    }
};