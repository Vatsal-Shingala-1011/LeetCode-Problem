class Solution {
private:
    void solve(vector<vector<int>>& ans,vector<int> nums,int index){
        int size=nums.size();
        if(index>=size){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<size;i++)
        {
            swap(nums[index],nums[i]);
            solve(ans,nums,index+1);
            //backtrack
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(ans,nums,index);
        return ans;
    }
};