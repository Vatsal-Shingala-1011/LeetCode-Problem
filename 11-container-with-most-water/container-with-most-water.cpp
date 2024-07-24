class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            int dis=j-i;
            ans = max(ans,min(nums[i],nums[j]) *dis);
            if(nums[i]<nums[j]) i++;
            else{
                j--;
            }
        }
        return ans;
    }
};