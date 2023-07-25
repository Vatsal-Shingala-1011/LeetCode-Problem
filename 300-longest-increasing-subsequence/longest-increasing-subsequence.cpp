class Solution {//Russian Doll optimize in one array
public:
    int solvememo(int n,vector<int>& nums,int curr,int prev,vector<vector<int>>& memo){
        if(curr==n)
            return 0;
        if(memo[curr][prev+1]!=-1) //perv+1 because in next if there is prev=-1
            return memo[curr][prev+1]; //so we shift cordinate by 1
        int take=0;
        if(prev==-1 || nums[curr]>nums[prev])
            take=1+solvememo(n,nums,curr+1,curr,memo);
        int nottake=solvememo(n,nums,curr+1,prev,memo);
        return memo[curr][prev+1]=max(take,nottake);
    }
    int solvetab2D(int n,vector<int>& nums){
        vector<vector<int>> memo(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){//shifted by 1 (prev only curr is same)//because prev index goes upto -1
                int take=0;                      //   cur->cur ,prev->prev+1 //index
                if(prev==-1 || nums[prev]<nums[curr])
                    take=1+memo[curr+1][curr+1]; 
                int nottake=memo[curr+1][prev+1];
                memo[curr][prev+1]=max(take,nottake);
            }
        }
        return memo[0][0];
    }
    int solvetab1D(int n,vector<int>& nums){//my method
        vector<int> memo(n+1,0);
        int maxi=0;
        for(int curr=0;curr<n;curr++){
            for(int prev=-1;prev<curr;prev++){
                int take;                      
                if(prev==-1)
                    take=1; 
                else if(nums[curr]>nums[prev])
                    take=1+memo[prev]; 
                //int nottake=memo[curr+1][prev+1];
                memo[curr]=max(memo[curr],take);
                maxi=max(memo[curr],maxi);
            }
        }
        return maxi;
    }
    int solve(vector<int>& nums){//Russian Doll optimize in one array
        int n=nums.size();
        if(n==0) return 0;
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>ans.back())
                ans.push_back(nums[i]);
            else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin(); //index
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
int solveopti(vector<int>& nums,int n )
{
    vector<int>currrow(n+1,0);
    vector<int>nextrow(n+1,0);
    for(int curr=n-1;curr>=0;curr--)
    {
        for(int prev=curr-1;prev>=-1;prev--)
        {
            // INCLUDE THE HEIGHT 
            int take=0;
            if(prev==-1 || nums[prev]<nums[curr])
                take=1+nextrow[curr+1]; 
            // EXCLUDE THE HEIGHT
            int notake= 0 + nextrow[prev+1];

            currrow[prev+1]=max(take,notake);  
        }
        // after every iteration upper row will be equal to currrow 
        nextrow=currrow;  
    }
    return nextrow[0];
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> memo(n,vector<int>(n+1,-1));
        // return solvememo(n,nums,0,-1,memo); 
        // return solvetab1D(n,nums);
        return solveopti(nums,n);
        // return solve(nums);
    }
};